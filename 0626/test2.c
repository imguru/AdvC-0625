
#include <string.h>
#include <stdio.h>

int main()
{
	char* s1 = "aaa";
	char* s2 = "bbb";

	printf("%d\n", strcmp(s1, s2));  // -1
	printf("%d\n", strcmp(s2, s1));

}
