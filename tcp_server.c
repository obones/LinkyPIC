/*
 LinkyPIC - The embedded program to talk with a Linky Utility meter, for a PIC16F18446

 The contents of this file are subject to the Mozilla Public License Version 1.1 (the "License");
 you may not use this file except in compliance with the License. You may obtain a copy of the
 License at http://www.mozilla.org/MPL/

 Software distributed under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
 ANY KIND, either express or implied. See the License for the specific language governing rights
 and limitations under the License.

 The Original Code is tcp_server.c.

 The Initial Developer of the Original Code is Olivier Sannier.
 Portions created by Olivier Sannier are Copyright (C) of Olivier Sannier. All rights reserved.
*/
#include <stdio.h>
#include <string.h>
#include "mcc_generated_files/mcc.h"
#include "tcp_server.h"
#include "notification_led.h"
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
    static uint8_t transmitBuffer[32];

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
            NotificationLEDMode = nlmError;
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
                
                // if no data was read, send a keep alive sequence anyway
                if (transmitLength == 0)
                {
                    NotificationLEDMode = nlmError;
                    
                    transmitLength = 2;
                    transmitBuffer[0] = 0x02;
                    transmitBuffer[1] = 0x03;
                }
                else
                {
                    NotificationLEDMode = nlmSynchronized;
                }
                
                // send data, if any
                if (transmitLength > 0)
                    TCP_Send(&serverSocket, transmitBuffer, transmitLength);
            }
            break;
        case SOCKET_CLOSING:
            TCP_SocketRemove(&serverSocket);
            NotificationLEDMode = nlmError;
            break;
            
        default:
            // we should not end up here
            break;
    }
}
