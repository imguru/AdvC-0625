#include <string.h>
#include <stdio.h>

int main()
{
	int n;
	char buf[512];
	scanf("%d", &n);
	printf("n: %d\n", n);

	getchar();
	while (fgets(buf, sizeof buf, stdin))
	{
		int len = strlen(buf);
		buf[len - 1] = '\0';

		printf("buf: %s\n", buf);
	}

#if 0
	while (gets(buf))
		printf("buf: %s\n", buf);
#endif
	
}

#if 0
int main()
{
	int age;
	char ch;

	// 42\n
	scanf("%d", &age);

	// fflush(stdin);
	// getchar();
	scanf(" %c", &ch);

	printf("%d %c\n", age, ch);

}
#endif
