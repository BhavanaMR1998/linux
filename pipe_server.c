#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char buffer[4];
	char buffer1[4];
	memset(buffer, '\0', sizeof(buffer));
	char data[100];
	int fd1[2];
	int fd2[2];
	int pipe_ret1=pipe(fd1);
	int pipe_ret2=pipe(fd2);
	pid_t fork_ret;
	while(1)
	{
		printf("Enter data for client process");
		fgets(data,100,stdin);
		fork_ret = fork();
		if(fork_ret==0)
		{
			sprintf(buffer, "%d", fd1[0]);
			sprintf(buffer1, "%d", fd2[0]);
(void)execl("pipe_client", "pipe_client", buffer,buffer1,(char*)0);
		}
		else
		{
			write(fd1[1], data, sizeof(data));
			read(fd2[0], data, sizeof(data));
			
			printf("\n recieved data is :%s", data);
		}
		printf("\n *************server end****************\n \n");
	}
}
