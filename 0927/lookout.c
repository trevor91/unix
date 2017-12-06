#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#define MFILE 10
void cmp(const char *, time_t);
struct stat sb;

int main(int argc, char **argv)
{
	int j;
	time_t last_time[MFILE+1];
	if(argc < 2)
	{
		fprintf(stderr, "usgae : lookout filename...\n");
		exit(1);
	}
	if(--argc > MFILE)
	{
		fprintf(stderr, "lookout : too many filenames\n");
		exit(1);
	}
	for(j = 1; j <=argc; j++)
	{
		if(stat(argv[j], &sb) == -1)
		{
			fprintf(stderr, "lookout : couldn't stat %s\n", argv[j]);
			exit(1);
		}
	}
	for(;;)
	{
		for(j=1;j<=argc;j++)
		{
			cmp(argv[j], last_time[j]);
		}
		sleep(5);
	}
	return 0;
}
void cmp(const char *name, time_t last)
{
	if(stat(name, &sb) == -1 || sb.st_mtime != last)
	{
		fprintf(stderr, "lookout : %s changed \n",name);
		exit(0);
	}
}

