#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void* thr_fn1(void *arg)
{
	printf("thread 1 returning\n");
	return((void*)1);
}

void* thr_fn2(void *arg)
{
	printf("thread 2 returning\n");
	pthread_exit((void*)100);
}

int main()
{
	int err;
	pthread_t tid1, tid2;
	void *tret;

	err = pthread_create(&tid1, NULL, thr_fn1, NULL);
	if(err != 0)
	{
		perror("can't create thread 1\n");
		exit(1);
	}
	err = pthread_create(&tid2, NULL, thr_fn2,NULL);
	if(err != 0)
	{
		perror("cant create thread 2\n");
		exit(1);
	}
	err = pthread_join(tid1, &tret);
	if(err !=0)
	{
		perror("can't join with thread 1\n");
		exit(1);
	}
	err = pthread_join(tid2, &tret);
	if(err !=0)
	{
		perror("can't join with thread 2\n");
		exit(1);
	}

	printf("thread 2 exit code %d\n", (int)tret);
	exit(0);
}

