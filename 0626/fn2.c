// 함수 포인터 활용: 함수의 인자를 통해 함수 포인터를 받는다.
//             => 어떤 동작을 수행할지 실행 시간에 결정한다.

#include <stdio.h>

void foo()
{
	printf("foo\n");
}

void goo()
{
	printf("goo\n");
}

void bar( void (*fp)() )
{
	fp();
	printf("bar\n");
}

int main()
{
	bar(foo);
	bar(goo);
}
