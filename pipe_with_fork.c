#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{

        	
        int fd[2];
	int fd2[2];
	int exit_code;
	int ret=pipe(fd);
	//int ret2=pipe(fd2);
	int pid=fork();

	if(pid<0)
	{
		perror("fork() creation is failed\n");
		exit(0);
	}
	else if(pid==0)
	{
		char buf[150];
		char crd_buf[150];

printf("Enter data from child to parent");
fgets(buf,150,stdin);
write(fd[1],buf,sizeof(buf));

//sleep(2);
//read(fd2[0], crd_buf, sizeof(crd_buf));
//printf("recieved data from parent to child is :%s", crd_buf);
exit(1);
	}
	else
	{
		int value;
		pid_t child_pid;
		char rd_buf[150];
                char pbuf[150];

		child_pid = wait(&value);
		read(fd[0], rd_buf, sizeof(rd_buf));
		printf("recieved data is :%s", rd_buf);
		//sleep(2);
		
//printf("Enter data from parent to child");
//fgets(pbuf,150,stdin);
//write(fd2[1],pbuf,sizeof(pbuf));



		close(fd[0]);
		close(fd[1]);

                close(fd2[0]);
                close(fd2[1]);
	}
}

