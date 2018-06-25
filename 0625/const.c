// const: 상수  
//  * 컴파일 타임 상수: 메모리 공간이 소모되지 않는다. 
//  * 런타임 상수: 메모리 공간이 존재한다. - *

#include <stdio.h>

int main()
{
	const int n = 42;
	int* p = (int*)&n;

	*p = 100;

	printf("%d\n", n);   // 42
	printf("%d\n", *p);  // 100
}
