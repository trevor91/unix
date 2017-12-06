#include <unistd.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
	pid_t pid;
	printf("calling fork()\n");
	pid = fork();
	if(pid > 0)
	{
		printf("paren: %d, %d, %d\n",pid, getpid(), getppid());
	}
	else if(pid == 0)
		printf("child: %d, %d, %d\n", pid,getpid(),getppid());
	else
		printf("err\n");
	return 0;
}

