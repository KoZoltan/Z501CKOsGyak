#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define MSGKEY 654321L

main()
{
	int msgid;
	int msgflg;
	int visszateres;
	key_t key;

	key = MSGKEY;
	msgflg = 00666 | IPC_CREAT; 

	msgid = msgget(key, msgflg); 

	visszateres = msgctl(msgid, IPC_RMID, NULL);	
	printf ("\n Visszatert: %d\n", visszateres);

	exit(0);
}
