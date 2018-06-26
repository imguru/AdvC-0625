#include <stdio.h>

int main()
{
	int i = 10;
	int *p = &i;
	int **pp = &p;
	int ***ppp = &pp;

	*p = 20;
	**pp = 20;
	***ppp = 20;

	// 32bit: pointer -> 4 byte
	// 64bit:         -> 8 byte

	printf("%ld\n", sizeof(ppp));    // 8
	printf("%ld\n", sizeof(*ppp));   // 8
	printf("%ld\n", sizeof(**ppp));  // 8
	printf("%ld\n", sizeof(***ppp)); // 4
}
