#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char**argv)
{
	pid_t pid;
	switch(pid = fork())
	{
		case -1:
			fprintf(stderr, "err\n");
			exit(-1);
			break;
		case 0:
			printf("my parrent process becomes zombie for 10secs.\n");
			break;
		defalut:
			sleep(10);
	}
	return 0;
}

