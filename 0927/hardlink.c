#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		perror("usage : ./mv <old> <new>\n");
		return -1;
	}
	if(link(argv[1], argv[2]))
	{
		printf("link failed : %s -> %s\n", argv[1], argv[2]);
		return -2;
	}
	if(unlink(argv[1]))
	{
		printf("unlink failed : %s\n", argv[1]);
		return -3;
	}
	printf("file moved : %s -> %s\n", argv[1], argv[2]);
	return 0;
}

