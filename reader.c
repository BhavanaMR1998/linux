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
       char *pointer_value1;
       char read_data[40];

       getcwd(cwd,sizeof(cwd));

       key = ftok(cwd,30);
       ret = shmget(key,size,IPC_CREAT | 0744);

       pointer_value1 = shmat(ret,(void*)0,0);
       printf("shared memory ID : %d\n",ret);



       printf("The read msg is: %s\n",pointer_value1);
       memcpy(pointer_value1,"Hello how are you all from reader?",40);

       shmdt(pointer_value1);


       return 0;
}
