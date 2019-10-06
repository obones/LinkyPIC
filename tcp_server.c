#include <stdio.h>
#include <string.h>
#include "mcc_generated_files/mcc.h"
#include "tcp_server.h"
#include "mcc_generated_files/TCPIPLibrary/tcpv4.h"
#include "mcc_generated_files/TCPIPLibrary/ipv4.h"
#include "mcc_generated_files/TCPIPLibrary/tcpip_config.h"

#define ListenPort 561

void TCP_Server(void)
{
    // socket
    static tcpTCB_t serverSocket;

    // TX and RX Server's buffers
    static uint8_t receiveBuffer[10];
    static uint8_t transmitBuffer[16];
    
    int16_t receivedLength;
    uint16_t transmitLength;
    socketState_t socket_state;

    socket_state = TCP_SocketPoll(&serverSocket);

    switch(socket_state)
    {
        case NOT_A_SOCKET:
            // Inserting and initializing the socket
            TCP_SocketInit(&serverSocket);
            break;
        case SOCKET_CLOSED:
            //configure the local port
            TCP_Bind(&serverSocket, ListenPort);
            // add receive buffer
            TCP_InsertRxBuffer(&serverSocket, receiveBuffer, sizeof(receiveBuffer));
            // start the server
            TCP_Listen(&serverSocket);
            break;
        case SOCKET_CONNECTED:
            // check if the buffer was sent, if yes we can send another buffer
            if(TCP_SendDone(&serverSocket))
            {
                // check to see  if there are any received data
                receivedLength = TCP_GetRxLength(&serverSocket);
                if(receivedLength > 0)
                {
                    receivedLength = TCP_GetReceivedData(&serverSocket);

                    // work with receiveBuffer to react to orders (none to date)
                    // if (receiveBuffer[0]) == 'H')
                    
                    // reuse the RX buffer
                    TCP_InsertRxBuffer(&serverSocket, receiveBuffer, sizeof(receiveBuffer));
                }
                
                // read any data from the Serial port
                transmitLength = 0;
                while (EUSART1_is_rx_ready() && transmitLength < sizeof(transmitBuffer))
                {
                    uint8_t readByte = EUSART1_Read();
                    if (!
                         (((((((readByte >> 4) | (readByte << 4)) ^ readByte) + 0x41) & 0x82) + 0x7E) & 0x80) // True if parity is odd
                            // taken from https://www.microchip.com/forums/FindPost/134006
                       )
                    {
                        transmitBuffer[transmitLength] = (uint8_t)(readByte & 0x7F);
                        transmitLength++;
                    }
                }
                
                // send data, if any
                if (transmitLength > 0)
                    TCP_Send(&serverSocket, transmitBuffer, transmitLength);
            }
            break;
        case SOCKET_CLOSING:
            TCP_SocketRemove(&serverSocket);
            break;
            
        default:
            // we should not end up here
            break;
    }
}
