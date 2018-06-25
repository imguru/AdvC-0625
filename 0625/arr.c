#include <stdio.h>

// C 언어에서 가장 혼란스러운 부분
// 1. type을 알아내는 방법
// 2. 포인터가 필요한 이유?
//    => Call by Rerefence

// void foo(int a[10]) // 3
void foo(int *a)
{
	printf("%ld\n", sizeof(a));  // ?
}

void goo(int (*a)[4])
{
	for (i = 0 ; i < 3 ; ++i)
		for (j = 0 ; j < 4 ; ++j)
			a[i][j] = i + j;
}

int main()
{
	int i, j;
	int arr[10];
	foo(arr);

	int a[3][4];    // a는 몇개짜리 배열인가요?
	

	goo(a);
}

#if 0
int main()
{
	int n;
	int *p = &n;
	
	int arr[10];
	// int[10] *p2 = &arr;   // int[10]*
	int (*p2)[10] = &arr;

	// 오른쪽에 오는 [], ()의 기호가 
	// 우선순위가 높다.
}
#endif

#if 0
int main()
{
	int n;       // int
	char c;      // char

	int arr[10];   // arr? int[10]
	// 배열의 타입은 개수도 포함된다.

	int* p = arr;  // 배열의 이름은 배열의 첫번째 원소의
	               // 시작주소로 해석된다.
	               // => Decay

	printf("%ld\n", sizeof(arr));  // 40

	// pp = &arr;

 	// 배열에 대해서는 decay의 연산이 항상 발생한다.
 	// => 예외 
 	//  1) sizeof
 	//  2) &

 
}
#endif
