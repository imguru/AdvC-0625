
#include <stdio.h>

class Test
{
public:
	void foo()           // foo(Test* this) {}
	{
		printf("foo\n");
	}
};



int main()
{
	// Test* test = new Test;
	Test* test = NULL;
	test->foo();       // foo(test);
	// ?
	// 1. Runtime Error
	// 2. Compile Error
	// 3. "foo"
	// 4. 알 수 없다.
}
