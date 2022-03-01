#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void main()
{

	char buffer[4];
	char buffer1[4];

	memset(buffer,'\0',sizeof(buffer));
	memset(buffer1,'\0',sizeof(buffer1));

	char data[100];//,*da = "This is from server\n";

	int fd1[2];
	int fd2[2];
	int num1,num2;
	char a ;
	char tx[4];

	int value;
	
	//int p_ret1 = pipe(fd1);
	int p_ret2 = pipe(fd2);

	pid_t fork_ret;
	while(1)
	{
	int i=0,j=0;
	char arr1[10]={0},arr2[10]={0};
	
	printf("Enter first number:");
	while((i = getchar()) != '\n')
	{
		arr1[j] = i;
		j++;
	}
	arr1[j] = '\0';
	j=0;
	printf("Enter second number:");
	while((i = getchar()) != '\n')
	{
		arr2[j] = i;
		j++;
	}
	arr2[j] = '\0';

	printf("Enter the sign:");
	i = getchar();
	
	
	//printf("i is %c\n",i);
    
	fork_ret = fork();
	 if(fork_ret == 0)
	 {
	 	//sprintf(buffer,"%d",fd1[0]);
	 	sprintf(buffer1,"%d",fd2[1]);
	 	if(i=='+')
	 		execl("./add","add",buffer1,arr1,arr2,NULL);//need to write
	 	if(i=='-')
	 		execl("./sub","sub",buffer1,arr1,arr2,NULL);//need to write
	 	if(i=='*')
	 		execl("./mul","mul",buffer1,arr1,arr2,NULL);//need to write
	 }
	 else
	 {
	 	
	 	//write(fd1[1],tx,4);

	 	//wait(&value);
	 	read(fd2[0],data,sizeof(data));

	 	printf("received data %s \n",data);

	 }
	 getchar();
	}
}



