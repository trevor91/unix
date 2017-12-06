#include <stdio.h>
#include <sys/stat.h>

static short octarray[9] = {
	0400,0200,0100,
	0040,0020,0010,
	0004,0002,0001};

static char perms[10] = "rwxrwxrwx";

int filedata(const char *pathname)
{
	struct stat statbuf;
	char descrip[10];
	int j;

	if(stat(pathname, &statbuf) == -1)
	{
		fprintf(stderr, "Couldn't stat %s\n",pathname);
		return -1;
	}
	for(j =0;j<9;j++)
	{
		if(statbuf.st_mode & octarray[j])
			descrip[j] = perms[j];
		else
			descrip[j] = '-';
	}
	descrip[9] = '\0';
	printf("\nfile : %s\n", pathname);
	printf("size %ld byte\n",statbuf.st_size);
	printf("user-id %d, group-id %d\n",statbuf.st_uid, statbuf.st_gid);
	printf("permissions : %s\n", descrip);
	return 0;
}

