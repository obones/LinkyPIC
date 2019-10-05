#include <string.h>
#include "mcc_generated_files/TCPIPLibrary/udpv4.h"
#include "udp_server.h"
#include "mcc_generated_files/TCPIPLibrary/ip_database.h"

const char ExpectedID[] = "LinkyPIC";

typedef struct 
{
    char ID[sizeof(ExpectedID)];
} ReceivedPacket_t;

void UDP_Server(int length)
{
    ReceivedPacket_t ReceivedPacket;
    
    UDP_ReadBlock(&ReceivedPacket, sizeof(ReceivedPacket));
    
    if (strcmp(ReceivedPacket.ID, ExpectedID) == 0)
    {
       error_msg ret = UDP_Start(ipv4Header.srcIpAddress, udpHeader.dstPort, udpHeader.srcPort);
       
       if(ret == SUCCESS)
       {
          UDP_Write32(ipdb_getAddress());
           
          UDP_Send();           
       }        
    }
}

