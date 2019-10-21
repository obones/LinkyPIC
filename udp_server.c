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

