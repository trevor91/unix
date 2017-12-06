#include <stdio.h>
#include <signal.h>

static void fpe(int unused)
{
	printf("SOGFPR caught\n");
}

int main()
{
	int error;
	struct sigaction act;
	sigemptyset(&act.sa_mask);

	act.sa_handler = fpe;
	sigaction(SIGFPE, &act, NULL);
	error = 4/0;
	return 0;
}

