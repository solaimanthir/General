/*Author: Solai*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
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
    int opt_ena                 = true;
    char* msg                   = "Hello there, you're talking to a UDP server";
    char buff[512]              = {0};
    struct sockaddr_in ser_addr = {0};
    struct sockaddr_in cli_addr = {0};

    //initialise structs and buff
    memset(&ser_addr, 0, sizeof(ser_addr));
    memset(&cli_addr, 0, sizeof(cli_addr));
    memset(buff, 0, sizeof(buff));

    /* create the socket */
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(-1 == sock_fd)
    {
        perror("server socket creation failed");
        goto ERR_RET;
    }

    //setting socket options
    ret = setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
            &opt_ena, sizeof(opt_ena));
    if(0 != ret)
    {
        perror("setsockopt for socket failed");
        exit(EXIT_FAILURE);
    }

    ser_addr.sin_family      = AF_INET;
    ser_addr.sin_addr.s_addr = INADDR_ANY;
    ser_addr.sin_port        = htons(SER_PORT_NUM);

    /*bind the socket with the address*/
    ret = bind(sock_fd, (struct sockaddr *)&ser_addr, sizeof(ser_addr));
    if(ret < 0)
    {
        perror("bind failed");
        close(sock_fd);
        goto ERR_RET;
    }

    addr_len = sizeof(cli_addr);
    msg_len = recvfrom(sock_fd, (char*)buff, sizeof(buff), MSG_WAITALL,
            (struct sockaddr*)&cli_addr, &addr_len);
    printf("Client: %s\n", buff);

    ret = sendto(sock_fd, (const void*)msg, strlen(msg), MSG_CONFIRM,
            (const struct sockaddr*)&cli_addr, addr_len);

    printf("Server: sent msg to client\n");

    close(sock_fd);
    exit(0);

ERR_RET:
    exit(EXIT_FAILURE);
}
