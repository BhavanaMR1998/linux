#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void main(int argc, char*argv[])
{
	printf("\n ****************client start ***************\n");

	char rd_buf[100];
	memset(rd_buf, '\0', sizeof(rd_buf));

	int fd,fd1;

	fd=atoi(argv[1]);
	fd1=atoi(argv[2]);

	read(fd, rd_buf, sizeof(rd_buf));
	printf("recieved data from server:%s \n",rd_buf);

	printf("Enter string:..");
	fgets(rd_buf, 100, stdin);
	

	write(fd1, rd_buf, sizeof(rd_buf));
	printf("\n ************client end**************\n");

}



