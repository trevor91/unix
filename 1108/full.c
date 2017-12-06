#include <stdio.h>
#include <assert.h>
#include <unistd.h>

#define BUFSIZE 32

int main()
{
	char buffer[BUFSIZE];
	pid_t pid;
	int fd[2][2];
	assert(pipe(fd[0]) == 0);
	assert(pipe(fd[1]) == 0);
	pid = fork();
	if(pid == 0)
	{
		close(fd[0][1]);
		close(fd[1][0]);
		write(fd[1][1], buffer, BUFSIZE);
		read(fd[0][0], buffer, BUFSIZE);
		printf("child Meg : %s\n",buffer);
	}
	else if(pid > 0)
	{
		close(fd[0][0]);
		close(fd[1][1]);
		write(fd[0][1],"hello",BUFSIZE);
		sleep(10);
		read(fd[1][0], buffer, BUFSIZE);
		printf("parent msg : %s\n", buffer);
	}
	return 0;
}

