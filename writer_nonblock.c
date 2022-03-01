#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/fcntl.h>

void main()
{
        int ret;
        int fd;
	
       ret = mkfifo("fifo23", 0666 | O_WRONLY | O_NON_BLOCK);
       printf("ret = %d\n", ret);


if(ret<0)
 perror("mkfifo error");
fd = open("fifo23", O_WRONLY);
printf("fd = %d errno = %d\n", fd,errno);
if(errno == ENXIO)
        perror("NO reader is available");
write(fd, "hello friends", 14);
printf("data has been written to fifo..\n");
close(fd);

