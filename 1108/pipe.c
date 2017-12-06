#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 32

int main()
{
	int fd[2];
	pid_t pid;
	char buf[BUFSIZE];
	pipe(fd);
	pid = fork();
	if(pid = 0)
		write(fd[1],"hello",BUFSIZE);
	else if(pid > 0)
	{
		read(fd[0], buf,BUFSIZE);
		printf("Message : %d %d %s\n", fd[0], fd[1], buf);
		wait(NULL);
	}
	return 0;
}

