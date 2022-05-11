#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd, ret;
	char buf[32];

	buf[0]=0;


        ret=mkfifo("fifo",00666);
	if (ret == -1) {
	    perror("mkfifo()");
	    exit(-1);
	}

	fd=open("fifo",O_RDWR);
	if (fd == -1) {
	    perror("open() hiba!");
	    exit(-1);
	}

	strcpy(buf,"Ez kerul bele\0");
	printf("irok a fifoba: %s:%d\n",buf,strlen(buf));
	write(fd,buf,strlen(buf)); 

	ret=read(fd,buf,32); // olvasok belole ugyanazt, ret: mennyit sikerult olvasni
	printf("read() olvasott %d byteot, ami a kovetkezo: %s\n",ret,buf);

	close(fd);

	unlink("fifoka");	// letorlom a fifomat az fs-rol
}
