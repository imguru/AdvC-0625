#include <stdio.h>

// CPU Context - x86	       32 / 64
//  IP(Instruction Pointer) => EIP, RIP
//  => PC(Program Counter)
//  SP(Stack Pointer)       => ESP, RSP
//  BP(Base Pointer)        => EBP, RBP

// jmp: IP의 주소를 변경한다.
// call: 복귀 주소를 스택에 저장하고, jmp 한다.
//  ret: 복쉬 주소를 pop 하고, jmp 한다. 

// 함수 호출 규약
// => 32bit
//    cdecl
//    stdcall

// => 64bit
//    64bit call
void foo()
{

}

void goo()
{

}


int add(int a, int b)
{
	return a + b;
}

int main()
{
	int n = add(10, 20);
	foo();
	goo();

	printf("n: %d\n", n);
}



#if 0
void foo(int a, int b, int c, int d, int e, int f, int g, int h)
{

}

int main()
{
	foo(10, 20, 30, 40, 50, 60, 70, 100);
	return 0;
}
#endif
