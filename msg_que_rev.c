#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

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


	struct msgbuf msg_type;

	
	getcwd(cwd,sizeof(cwd));

	key = ftok(cwd,30);
	printf("key :%d\n",key);

	msg_qid = msgget(key,IPC_CREAT|0666);

	printf("msg_qid : %d \n",msg_qid);

	ret= msgrcv(msg_qid,&msg_type,sizeof(msg_type),1,0);

	printf("Msg from Tx: %s\n",msg_type.mtext);

	return 0;
}

