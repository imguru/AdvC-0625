#include <stdio.h>

// sort를 일반화하는 방법
#if 0
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void swap(double *a, double *b)
{
	double temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
#endif

// 인자를 char*, type의 size를 받는다.
#if 0
void swap(char *a, char *b, int size)
{
	char temp;
	int i;

	for (i = 0; i < size; ++i, ++a, ++b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
#endif
// void*
//  : 모든 포인터 타입을 수용할 수 있는 타입이다.
//  => 대상체의 크기를 알 수 없기 때문에
//     포인터의 대부분의 연산을 사용할 수 없다.
void swap(void *a, void *b, int size)
{
	char temp;
	int i;

#if 0
	char* p = (char*)a;
	char* q = (char*)b;
#endif
	// GNU 확장 문법
	//  : void*에 대해서 ++, +, -, -- 연산은 1바이트 단위로 취급해서
	//    동작한다.

	for (i = 0; i < size; ++i, ++a, ++b)
	{
		temp = *(char*)a;
		*(char*)a = *(char*)b;
		*(char*)b = temp;
	}
}


int main()
{
	int a = 10;
	int b = 20;

	// swap(&a, &b);
	// swap((char*)&a, (char*)&b, sizeof a);
	// 사용자가 매번 캐스팅을 해줘야 하는 부담이 있다.

	swap(&a, &b, sizeof a);

	printf("a: %d\n", a);
	printf("b: %d\n", b);
}









