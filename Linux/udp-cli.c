/*Author: Solai*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SER_PORT_NUM 50123

int main()
{
    int ret                     = 0;
    int sock_fd                 = 0;
    int addr_len                = 0;
    int msg_len                 = 0;
    char* msg                   = "Hello there, this is a UDP client";
    char buff[512]              = {0};
    struct sockaddr_in ser_addr = {0};

    //initialise structs and buff
    memset(&ser_addr, 0, sizeof(ser_addr));
    memset(buff, 0, sizeof(buff));

    /* create the socket */
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(-1 == sock_fd)
    {
        perror("client socket creation failed");
        goto ERR_RET;
    }

    ser_addr.sin_family      = AF_INET;
    ser_addr.sin_addr.s_addr = INADDR_ANY;
    ser_addr.sin_port        = htons(SER_PORT_NUM);

    /*binding of client socket with the address not necessary*/
    //ignore bind

    /*send msg to server*/
    ret = sendto(sock_fd, (const void*)msg, strlen(msg), MSG_CONFIRM,
            (const struct sockaddr*)&ser_addr, sizeof(ser_addr));
    if(-1 == ret)
    {
        perror("sendto() error");
        close(sock_fd);
        goto ERR_RET;
    }

    printf("Client: msg sent to server\n");

    addr_len = sizeof(ser_addr);
    /*rx msg from server*/
    msg_len = recvfrom(sock_fd, (char*)buff, sizeof(buff), MSG_WAITALL,
            (struct sockaddr*)&ser_addr, &addr_len);
    if(-1 == msg_len)
    {
        perror("recvfrom() error");
        close(sock_fd);
        goto ERR_RET;
    }

    printf("Server: %s\n", buff);

    /*close the fd and exit*/
    close(sock_fd);
    exit(0);

ERR_RET:
    exit(EXIT_FAILURE);
}
