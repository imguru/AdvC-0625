#include <stdio.h>

int main()
{
	int (**p)[2][2] = 0;

	printf("p+1: %p\n", p + 1);
}

#if 0
int main()
{
	int (*p)[2][2] = 0;

	printf("%p\n", p + 1);
}
#endif

#if 0
int main()
{
	int *a[2][2];

	int*(*p)[2];
	// p = a;

	p = NULL;

	printf("%p\n", p + 1);


}

#endif
