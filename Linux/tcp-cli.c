/*Author: Solai*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>   // INADDR_ANY
#include <arpa/inet.h>    // for inet_pton

#define SER_PORT_NUM 50123
#define LOCALHOST_IP "127.0.0.1"

int main()
{
    int cli_fd              = 0;
    int read_len            = 0;
    int ret                 = 0;
    char buff[512]          = {0};
    char* msg               = "Hello there, I am TCP client";
    struct sockaddr_in addr = {0};

    memset(&addr, 0, sizeof(addr));

    cli_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == cli_fd)
    {
        perror("client socket creation failed");
        goto ERR_RET;
    }

    ret = inet_pton(AF_INET, LOCALHOST_IP, &addr.sin_addr);
    if(ret <= 0)
    {
        perror("invalid address");
        close(cli_fd);
        goto ERR_RET;
    }

    addr.sin_family = AF_INET;
    addr.sin_port   = htons(SER_PORT_NUM);

    ret = connect(cli_fd, (struct sockaddr *)&addr, sizeof(addr));
    if(-1 == ret)
    {
        perror("connect() failed");
        close(cli_fd);
        goto ERR_RET;
    }

    send(cli_fd, msg, strlen(msg), 0);

    close(cli_fd);
    exit(0);

ERR_RET:
    exit(EXIT_FAILURE);
}
