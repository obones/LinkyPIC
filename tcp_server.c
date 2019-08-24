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
    
    uint16_t receivedLength, transmitLength, i;
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

                    //simulate some buffer processing
                    for(i = 0; i < receivedLength; i++)
                    {
                        transmitBuffer[i] = receiveBuffer[i]; //EUSART1_Read();
                    }

                    // reuse the RX buffer
                    TCP_InsertRxBuffer(&serverSocket, receiveBuffer, sizeof(receiveBuffer));
                    transmitLength = receivedLength;
                    //send data back to the source
                    TCP_Send(&serverSocket, transmitBuffer, transmitLength);
                }
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
