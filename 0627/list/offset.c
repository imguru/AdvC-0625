#include <stdio.h>
#include <stddef.h>

typedef struct node
{
	struct node *prev;
	struct node *next;
} NODE;

typedef struct
{
	NODE links; // 12
	int a;
	int b;
	int c;
} USER ;

// #define offsetof(type, member)	(size_t)&(((type*)0)->member)

// 구조체 멤버의 offset을 구하는 방법
int main()
{
	// &(*p).links => &*12  => 12

	printf("%ld\n", 
		(unsigned long)&(((USER*)0)->b));

	printf("%ld\n", offsetof(USER, a));
	printf("%ld\n", offsetof(USER, b));
	printf("%ld\n", offsetof(USER, c));
	printf("%ld\n", offsetof(USER, links));
}















