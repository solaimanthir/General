#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUFFER_SZ
#define BUFFER_SZ 512
#endif

int main(int argc, char *argv[])
{
    int infd = 0;
    int outfd = 0;
    char buffer[BUFFER_SZ] = {0};
    ssize_t rcount = 0;
    ssize_t wcount = 0;
    int ret = 0;

    if(argc != 3 || (strcmp(argv[1], "--help") == 0))
    {
        printf("%s src-file dest-file\n", argv[0]);
        exit(0);
    }

    infd = open(argv[1], O_RDONLY);
    if(-1 == infd)
    {
        printf("error in opening source file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    outfd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if(-1 == outfd)
    {
        printf("error in opening destination file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    /*read and write data*/
    while(1)
    {
        rcount = read(infd, buffer, BUFFER_SZ);
        if(-1 == rcount)
        {
            printf("read error\n");
            exit(EXIT_FAILURE);
        }
        if(rcount <= 0)
        {
            //end of file or error
            break;
        }

        wcount = write(outfd, buffer, rcount);
        if(wcount != rcount)
        {
            printf("write error\n");
            exit(EXIT_FAILURE);
        }
    }

    ret = close(infd);
    if(-1 == ret)
    {
        printf("error in closing src file\n");
        exit(EXIT_FAILURE);
    }

    ret = close(outfd);
    if(-1 == ret)
    {
        printf("error in closing dest file\n");
        exit(EXIT_FAILURE);
    }

    //success
    return 0;
}
