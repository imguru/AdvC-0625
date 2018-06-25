#include <stdio.h>

int main()
{
	int n = 42;
	int *p = &n;

	int **pp = &p;
	int ***ppp = &pp;

	*p = 100;
	// n = 100

	**pp = 200;
	// *p = 200
	//  n = 200
}
