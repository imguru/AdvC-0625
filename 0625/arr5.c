#include <stdio.h>
int main()
{
	int a[2][2] = {1,2,3,4};

	// int (*p)[2] = a;
	int** p = a;

	p[1][1] = 10;
}

