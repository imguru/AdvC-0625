#include <stdio.h>

int main()
{
	int data[10] = { 1, 2, 3, 4, 5 };

	int* p = data + 3;
	printf("%d\n", p[-1]);

}
