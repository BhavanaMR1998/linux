#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
       



int main()
{
       int ret;
       char cwd[100];
       key_t key;
       int size =500;
       char *pointer_value;

       getcwd(cwd,sizeof(cwd));

       key = ftok(cwd,30);
       ret = shmget(key,size,IPC_CREAT | 0744);
       printf("shared memory ID  : %d\n",ret);

       pointer_value = shmat(ret,(void*)0,0);

       memcpy(pointer_value,"Hello how are you all?",30);

       sleep(10);

       printf("The msg from reader is : %s \n",pointer_value);

       


       shmdt(pointer_value);


       return 0;
}
