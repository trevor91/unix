#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "hotel.h"
#include "getoccupier.h"

#define LINELENGTH 4

char buffer[LINELENGTH];
char *getoccupier(int roomno)
{
	off_t offset;
	ssize_t nread;

	if(listfiledes == -1 && (listfiledes = open(listfile, O_RDONLY)) ==-1)
	{
		fprintf(stderr,"error on opening list file\n");
		return NULL;
	}

	offset = (roomno -1 ) * LINELENGTH;

	if(lseek(listfiledes, offset, SEEK_SET) == -1)
	{
		fprintf(stderr, "ERROR on SETTING OFFSET\n");
		return NULL;
	}
	if((nread = read(listfiledes, buffer, LINELENGTH)) <0 )
	{
		fprintf(stderr, "Error on reading list file\n");
		return NULL;
	}
	buffer[LINELENGTH-1] = '\0';
	return buffer;
}

