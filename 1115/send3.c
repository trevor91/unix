#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define FIFO "./fifo"
#define BUFSIZE 512

int fd;
void sigproc()
{
	close(fd);
	unlink(FIFO);
	exit(0);
}


int main()
{
	int fd;
	char buffer[BUFSIZE];
	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_handler = sigproc;
	act.sa_flags = SA_ONESHOT;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	sigaction(SIGTSTP, &act, NULL);
	if(mkfifo(FIFO, 0600) == -1)
	{
		return -1;
	}
	fd = open(FIFO, O_WRONLY);
	while(1)
	{
		printf("> ");
		if(fgets(buffer, BUFSIZE-1, stdin) <= 0)
		{
			break;
		}
		write( fd, buffer, BUFSIZE);
	}
	sigproc();
	return 0;
}

