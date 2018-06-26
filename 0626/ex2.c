#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(char*** name, int* n)
{
	printf("몇 명?");
	scanf("%d", n);
	getchar();

	*name = (char**)malloc(sizeof(char*) * (*n));
}

int main()
{
	char buf[1024];
	char** name;
	int i;
	int n;
	
	init(&name, &n);

	for (i = 0 ; i < n ; ++i)
	{
		fgets(buf, sizeof buf, stdin);
		buf[strlen(buf) - 1] = 0;

		name[i] = strdup(buf);
	}

	for (i = 0 ; i < n ; ++i)
		printf("%s\n", name[i]);

	for (i = 0 ; i < n ; ++i)
		free(name[i]);

	return 0;
}
#if 0
int main()
{
	char buf[1024];
	char* name[3];
	int i;

	for (i = 0 ; i < 3 ; ++i)
	{
		fgets(buf, sizeof buf, stdin);
		buf[strlen(buf) - 1] = 0;

		name[i] = strdup(buf);
#if 0
		name[i] = (char*)malloc(strlen(buf) + 1);
		strcpy(name[i], buf);
#endif
	}

	for (i = 0 ; i < 3 ; ++i)
		printf("%s\n", name[i]);

	for (i = 0 ; i < 3 ; ++i)
		free(name[i]);

	return 0;
}
#endif

// 사람마다 이름의 길이가 다르다.
// => 포인터 배열을 도입해서 동적 할당을 하도록 변경하자.
#if 0
int main()
{
	char name[3][32];
	int i;

	for (i = 0 ; i < 3 ; ++i)
		fgets(name[i], sizeof name[i], stdin);

	for (i = 0 ; i < 3 ; ++i)
		printf("%s\n", name[i]);

	return 0;
}
#endif
#if 0
int main()
{
	char name[32];

	fgets(name, sizeof name, stdin);
	printf("%s\n", name);

	return 0;
}
#endif
