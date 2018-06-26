#include <stdio.h>
#include <stdlib.h>
// qsort라는 quick sort 함수가 있습니다.

void swap(void *a, void *b, int size)
{
	char temp;
	int i;

	char* p = (char*)a;
	char* q = (char*)b;

	for (i = 0; i < size; ++i, ++p, ++q)
	{
		temp = *p;
		*p = *q;
		*q = temp;
	}
}


// NlogN 
//  quick sort
//  heap  sort
#if 0
void bsort(int *a, int n)
{
	int i, j;
	for (i = 0 ; i < n - 1; ++i)
	{
		for (j = 0 ; j < n - 1 - i; ++j)
		{
			if (a[j] > a[j+1])
				swap(&a[j], &a[j+1], sizeof a[0]);
		}
	}
}
#endif
// n: 전체 원소의 개수
// size: 하나의 원소의 크기 
// 핵심: 값의 비교가 필요한 정책은 사용자가 결정한다.
//  => 변하지 않는 알고리즘은 두고, 변하는 정책은 사용자로부터 받아야 한다.
//  => 함수의 인자를 통해서 함수 포인터를 통해 분리한다.
#if 0
void bsort(void *a, int n, int size)
{
	int i, j;
	for (i = 0 ; i < n - 1; ++i)
	{
		for (j = 0 ; j < n - 1 - i; ++j)
		{
			if ( *(int*)((char*)a + (size * j)) > *(int*)((char*)a + (size * (j + 1))) )
				// swap(&a[j], &a[j+1], sizeof a[0]);
				swap((char*)a + j * size, (char*)a + (j+1) * size, size);
		}
	}
}
#endif

// cmp -> strcmp
//  왼쪽이 클때 : 0 보다 작은 값 
//  같을 때     : 0
// 오른쪽이 클때: 0 보다 큰 값
void bsort(void *a, int n, int size, int (*cmp)(const void *, const void *))
{
	int i, j;
	for (i = 0 ; i < n - 1; ++i)
	{
		for (j = 0 ; j < n - 1 - i; ++j)
		{
			if (cmp((char*)a + j * size, (char*)a + (j+1) * size) > 0)
				swap((char*)a + j * size, (char*)a + (j+1) * size, size);
		}
	}
}

int cmp_int2(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}


int cmp_int(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int i;
	int a[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	qsort(a, 10, sizeof a[0], cmp_int);

	for (i = 0 ; i < 10 ; ++i)
		printf("%3d", a[i]);
	printf("\n");
}








