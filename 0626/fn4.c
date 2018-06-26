#include <stdio.h>
int (*bbb(void))[2]
{
	static int a[2][2] = { 1, 2, 3, 4 };
	return a;
}

int (*(*aaa(void))(void))[2]
{
	return bbb;
	// int (*(*)(void))[2]
}

int main()
{
	printf("%d\n", aaa()()[0][1]);
}
