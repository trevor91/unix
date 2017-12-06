#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int listdir(char *path)
{
	DIR *dirp;
	struct dirent *dir;

	if((dirp = opendir(path)) == NULL)
	{
		fprintf(stderr, "Error on open directroy\n");
		return -1;
	}
	while((dir = readdir(dirp)) != NULL)
	{
		printf("%s\n", dir->d_name);
	}
	closedir(dirp);
	return 0;
}
