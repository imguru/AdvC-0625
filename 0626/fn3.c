// Modern Programming Language
//  => OOP + FP
//           (고계 함수 - High-Order Function)
//            : 함수를 인자로 받거나 함수를 반환하는 함수
//          => 프로그래밍 언어가 함수를 참조할 수 있어야 한다.
//          => 함수를 일급 시민으로 취급해야 한다.

// 리팩토링: 코드의 구조를 개선하는 작업(Java)
//   => 마틴 파울러
// 2판: Javascript
#include <stdio.h>

int bbb(int data)
{
	return data;
}

aaa()
{
	return bbb;
}


int main()
{
	aaa()(1);
}

#if 0
// 함수 포인터를 반환하는 함수
#include <stdio.h>

void foo()
{
	printf("foo()\n");
}

void (*bar())()
{
	printf("bar()\n");
	return foo;
}

int main()
{
	bar()();
}
#endif








