#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/fcntl.h>

void main()
{
	int ret = open("fifo23", 0666 | O_RDONLY | O_NONBLOCK);
	printf("ret = %d \n", ret);
	if(ret<0)
		perror("Error in open");
	char data[100];
	read(ret, data, 100);
	printf("received = %s", data);
	close(ret);
}

