#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void listdir(char *path, int dirdepth)
{
	DIR *dirp;
	struct dirent *dir;
	struct stat status;
	int i;

	if((dirp = opendir(path)) ==NULL)
		return;

	chdir(path);

	while((dir = readdir(dirp)) != NULL)
	{
		stat(dir->d_name, &status);
		if(S_ISDIR(status.st_mode))
		{
			if(strncmp(".",dir->d_name,1) == 0 || strncmp("..", dir->d_name, 2) == 0)
				continue;
			printf("%*s%s\n", dirdepth, "", dir->d_name);
			listdir(dir->d_name, dirdepth+3);
		}
		else
			printf("%*s%s\n", dirdepth, "", dir->d_name);
	}
	closedir(dirp);
}

