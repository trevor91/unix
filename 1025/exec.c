#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	switch(pid = fork())
	{		
	case -1:
		printf("fork failed\n");
		break;
	case 0:
		execl("/bin/ls","ls","-l",(char*)0);
		printf("exec failed");
		break;
	default:
		wait((int*)0);
		printf("ls completed\n");
		exit(0);
	}
	return 0;
}

