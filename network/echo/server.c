#include "headerFiles.h"

#define SERVER_PORT 8888

int main(void)
{
    //define env and var
    int s;
    int len;
    char buffer[256];
    struct sockaddr_in servAddr;
    struct sockaddr_in clntAddr;
    int clntAddrLen;
    
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SERVER_PORT);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        printf("socket error: %d, %s\n", errno, strerror(errno));
        exit(1);
    }

    if ((bind(s, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0))
    {
        printf("bind error: %d, %s\n", errno, strerror(errno));
        exit(1);
    }
    
    for(; ;)
    {
        len = recvfrom(s, buffer, sizeof(buffer), 0, 
                   (struct sockaddr*)&clntAddr, &clntAddrLen);
    
        sendto(s, buffer, len, 0, (struct sockaddr*)&clntAddr, 
                sizeof(clntAddr));
    }
}
    
