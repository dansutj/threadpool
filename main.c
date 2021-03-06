#include "threadpool.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void* mytask(void* arg)
{
	printf("thread 0x%x is working in task %d\n", (int)pthread_self(), *(int*)arg);
	sleep(1);
	free(arg);
	return NULL;
}


int main(void)
{
	threadpool_t pool;
	threadpool_init(&pool, 3);

	for(int i = 0; i < 10; ++i)
	{
		int* arg = (int*)malloc(sizeof(int));
		*arg = i;
			
		threadpool_add_task(&pool, mytask, arg);
	}

	threadpool_destroy(&pool);
	return 0;
}


