#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>

struct msgbuf 
{
    long mtype;       /* message type, must be > 0 */
    char mtext[100];    /* message data */
};


int main()
{
	key_t key;
	char cwd[200];
	int msg_qid,ret;

    char mmmsg[100] = "Im in message que";
	struct msgbuf msg_type;

    strcpy(msg_type.mtext,mmmsg);
    printf("%s \n",msg_type.mtext);
	//msg_type.mtext = mmmsg;  
	msg_type.mtype = 1;

	getcwd(cwd,sizeof(cwd));

	key = ftok(cwd,30);
	printf("key :%d\n",key);

	msg_qid = msgget(key,IPC_CREAT|0666);

	printf("msg_qid : %d \n",msg_qid);

	ret= msgsnd(msg_qid,&msg_type,sizeof(msg_type),0);



	return 0;
}
