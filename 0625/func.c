#include <stdio.h>

// 배열 포인터 / 함수 포인터
typedef int (*myarr_t)[2];
// int (*foo())[2]
myarr_t foo()
{
	static int a[2][2]; 
	return a;          
	// int (*foo())[2]
}

int main()
{
	int (*p)[2] = foo();
	p[1][1] = 10;

	foo()[1][1] = 10;
	printf("%d\n", foo()[1][1]);
}

