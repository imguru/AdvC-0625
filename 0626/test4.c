#include <stdio.h>

#define POW(x) ((x) * (x))

// GNU 확장 문법 
static inline int xpow(int a)
{
	return a * a;
}

int main()
{
	int n = 0;
	printf("%d\n", xpow(++n));
}
