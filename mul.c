#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void main(int argc, char * argv[])
{
	printf("-----client start-------\n");

	char rd_buf[100],buff[4],*dat1 = "This is from client";
	memset(rd_buf,'\0',sizeof(rd_buf));

	int fd1;
	int fd2;
	int n1;
	int n2;
	int n3;
	//printf("%s \n %s \n %s \n %s\n",argv[0],argv[1],argv[2],argv[3]);

	fd2 = atoi(argv[1]);
	//fd2 = atoi(argv[2]);
	n1 = atoi(argv[2]);
	n2 = atoi(argv[3]);

	//printf("fd2 is %d\n",fd2);
	n3 = n1*n2;

	//read(fd1,rd_buf,sizeof(rd_buf));
	//printf("Received data from server: %s \n",rd_buf);

	//printf("Enter the string -------:\n");
	sprintf(buff,"%d",n3);

	write(fd2,buff,50);

	printf("\n------client end-------\n");
}
