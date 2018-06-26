#include <stdio.h>

// typedef: 복잡한 표현식을 간략화 할 수 있다.

typedef int (*FP1)[2];
typedef FP1 (*FP2)(void);

// int (*bbb(void))[2]
FP1 bbb(void)
{
	static int a[2][2] = { 1, 2, 3, 4 };
	return a;
}

// int (*(*aaa(void))(void))[2]
FP2 aaa(void)
{
	return bbb;
	// int (*(*)(void))[2]
	// FP1 (*)(void)
}

int main()
{
	printf("%d\n", aaa()()[0][1]);
}
