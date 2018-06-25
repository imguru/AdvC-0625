#include <stdio.h>
#include <pthread.h>

void* foo(void* p)
{
	volatile int* n = (int*)p;
	while (*n)
	{

	}

	printf("end\n");
}


int main()
{
	pthread_t thread;
	int n = 1;
	pthread_create(&thread, NULL, &foo, &n);
	getchar();
	n = 0;
	pthread_join(thread, NULL);

	printf("main end\n");
	return 0;
}
