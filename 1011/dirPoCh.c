#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{

	char name[256];
	int i,res;
	printf("Current dir. : %s\n", getcwd(name,256));
	for(i=1;i<argc;i++)
	{
		res = chdir(argv[i]);
		if(res)
			printf("chdir for %s failed.\n", argv[i]);
		else
			printf("Current dir. : %s\n", getcwd(name,256));
	}

	return 0;
}

