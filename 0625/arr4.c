#include <stdio.h>

int main()
{
	int a[4] = {1,2,3,4};
	int *p = a;

	printf("%ld", sizeof(p));      // 8
	printf("%ld", sizeof(int*));   // 8
	printf("%ld", sizeof(a));      // 16
	printf("%ld", sizeof(int[4])); // 16
}

