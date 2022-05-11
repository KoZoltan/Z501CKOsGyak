#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main(int argc, char **argv) {
    struct msqid_ds ds, *buf;
    struct msgbuf1 {
	long mtype;
	long pid;
    } recvbuf, *msgp;

    int pid;
    int msgid = msgget(ftok("/user/zoli",1),00666|IPC_CREAT);
    if(msgid==-1){
        perror(": msgget() nem sikerult letrehozni!");
    exit(-1);
    }

    msgp = &recvbuf;
	buf = &ds;		
    int	msgsz = 30;	
    int	mtype = 0;
	

	 msgctl(msgid, IPC_STAT, buf);
	printf("Az uzenetek szama az uzenetsorban: %d\n", buf->msg_qnum);

	while (buf->msg_qnum) {

		msgrcv(msgid,(struct msgbuf *)msgp, msgsz, mtype, 0666);
		printf("msgrcv() visszaadta: , a kapott uzenet: %d\n", msgp->pid);
		msgctl(msgid, IPC_STAT, buf);

	}


    return 0;
}
