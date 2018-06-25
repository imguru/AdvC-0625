#include <stdio.h>

// 배열의 참조 연산
void foo(int* p)
{
	p[1] = 20;
	// *(p + 1) = 20;
}

int main()
{
	int arr[3] = { 1, 2, 3 };

	arr[0] = 10;
	foo(arr);
	// *(arr + 0) = 10;
	// *(0 + arr) = 10;
	// 0[arr] = 20;

	// *& => 상쇄
	// printf("%d\n", *&*&*&*&*&*&*&*&arr[0]);


}
