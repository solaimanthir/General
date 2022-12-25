/*Author: Solai*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h> //INADDR_ANY

#define PORT_NUM    50123
#define RET_SUCCESS 0
#define QUEUE_LEN   100

int main(int argc, char* argv[])
{
    int ser_list_fd = 0;
    int ser_conn_fd = 0;
    int read_len    = 0;
    int addr_len    = sizeof(struct sockaddr_in);
    int opt_ena     = true;
    int ret         = 0;
    char buff[512]  = {0};
    struct sockaddr_in sock_addr;

    memset(&sock_addr, 0, sizeof(sock_addr));

    //create listening fd for the server
    ser_list_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(0 == ser_list_fd)
    {
        perror("server's listening socket creation failed");
        exit(EXIT_FAILURE); 
    }

    //setting socket options
    ret = setsockopt(ser_list_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
		    &opt_ena, sizeof(opt_ena));
    if(RET_SUCCESS != ret)
    {
        perror("setsockopt for listening socket failed");
        exit(EXIT_FAILURE);
    }

    sock_addr.sin_family      = AF_INET;
    sock_addr.sin_addr.s_addr = INADDR_ANY;
    sock_addr.sin_port        = htons(PORT_NUM);

    //bind listening socket to the address(IP and port)
    ret = bind(ser_list_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));
    if(ret < 0)
    {
        perror("bind of listening socket to address failed");
        exit(EXIT_FAILURE);
    }

    ret = listen(ser_list_fd, QUEUE_LEN);
    if(ret < 0)
    {
        perror("listen() call failed");
        exit(EXIT_FAILURE);
    }

    ser_conn_fd = accept(ser_list_fd, (struct sockaddr *)&sock_addr, 
		    (socklen_t *)&addr_len);
    if(-1 == ser_conn_fd)
    {
        perror("accept() call failed");
        exit(EXIT_FAILURE);
    }

    read_len = read(ser_conn_fd, buff, 512);
    printf("Message: %s\n", buff);

    close(ser_conn_fd);
    close(ser_list_fd);
    exit(0);
}
