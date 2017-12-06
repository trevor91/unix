#include "hotel.h"
#include "getoccupier.h"
#include <stdio.h>

#ifndef NROOMS
#define NROOMS 10
#endif

int main()
{
	char* name;
	int i;

	printf("read occupiers from file : %s\n", listfile);

	for(i = 1;i <=NROOMS; i++)
	{
		if(name=getoccupier(i))
		{
			printf("ROOM %d, %s\n",i,name);
		}
		else
		{
			fprintf(stderr, "Error on calling 'get..oc..\n");
		}
	}
	return 0;
}


