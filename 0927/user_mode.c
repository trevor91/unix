#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PERM 0777

int main()
{
	char *filename = "afile";
	if(access(filename, R_OK) == -1)
	{
		fprintf(stderr, "user cannot read file %s\n", filename);
		exit(1);
	}
	printf("%s readable, proceeding\n", filename);
	if(chmod(filename, PERM) == -1)
		perror("call to chmod failed");
	if(chown(filename, 1000, 3) == -1)
		perror("call to chown failed");
	return 0;
}
