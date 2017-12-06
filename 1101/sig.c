#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

static void fpe(int unuserd)
{
	printf("SIGFPE caught.\n");
	exit(1);
}

int main()
{
	int error;
	signal(SIGFPE, fpe);
	error = 4/0;
	return 0;
}

