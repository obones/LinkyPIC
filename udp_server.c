/*
 LinkyPIC - The embedded program to talk with a Linky Utility meter, for a PIC16F18446

 The contents of this file are subject to the Mozilla Public License Version 1.1 (the "License");
 you may not use this file except in compliance with the License. You may obtain a copy of the
 License at http://www.mozilla.org/MPL/

 Software distributed under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
 ANY KIND, either express or implied. See the License for the specific language governing rights
 and limitations under the License.

 The Original Code is udp_server.c.

 The Initial Developer of the Original Code is Olivier Sannier.
 Portions created by Olivier Sannier are Copyright (C) of Olivier Sannier. All rights reserved.
*/
#include <string.h>
#include "mcc_generated_files/TCPIPLibrary/udpv4.h"
#include "udp_server.h"
#include "mcc_generated_files/TCPIPLibrary/ip_database.h"
#include "mcc_generated_files/TCPIPLibrary/network.h"

#define ExpectedID "LinkyPIC"

typedef struct 
{
    char ID[sizeof(ExpectedID) - 1];
} ReceivedPacket_t;

void UDP_Server(int length)
{
    ReceivedPacket_t ReceivedPacket;
    
    if (length == (int)sizeof(ReceivedPacket))
    {
        UDP_ReadBlock(&ReceivedPacket, sizeof(ReceivedPacket));

        if (memcmp(ReceivedPacket.ID, ExpectedID, sizeof(ReceivedPacket)) == 0)
        {
           error_msg ret = UDP_Start(ipv4Header.srcIpAddress, udpHeader.dstPort, ntohs(udpHeader.srcPort));

           if(ret == SUCCESS)
           {
              UDP_Write32(ipdb_getAddress());

              UDP_Send();           
           }        
        }
    }
}

