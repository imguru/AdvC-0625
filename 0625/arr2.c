#include <stdio.h>
void foo(int* arr)
{

}

void goo(int (*arr)[4])
{

}

int main()
{
	int arr2[3][4];
	int arr[4];  // int[4]
				 // 배열의 이름은 배열의 첫번째 원소의 시작주소로
				 // 해석된다.
				 //  => int*
				 //  예외)
				 //     1) sizeof
				 //     2) &
	foo(arr);
	// goo(&arr);  // &int[4]
	goo(arr2);
}










