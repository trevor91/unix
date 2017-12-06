#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define FIFO "./fifo"
#define BUFSIZE 512
#define MODE 0660

int main()
{
	int fd;
	char buffer[BUFSIZE];
	if(mkfifo(FIFO, MODE) == -1)
	{
		printf("err on mkfifo\n");
		return -1;
	}
	while((fd=open(FIFO, O_WRONLY|O_NONBLOCK)) < 0)
	{
		if( errno != ENXIO)
		{
			return -2;
		}
		printf("no process is reading, waitint 1sec\n");
		sleep(1);
	}
	while(1)
	{
		printf("> ");
		if(fgets(buffer, BUFSIZE-1, stdin) <= 0)
		{
			break;
		}
		write( fd, buffer, BUFSIZE);
	}
	close(fd);
	unlink(FIFO);
	return 0;
}

