#include <stdio.h>
#include <stdlib.h>

// Flexiable Array
struct flex
{
	int info;
	int count;
	int data[];   // 구조체의 마지막 멤버에 위치해야 한다.
	// int data[0]
	// int data[1]
};

struct flex *init_data(int count)
{
	struct flex *fa = malloc(sizeof(struct flex) + sizeof(int) * count);
	fa->count = count;
	return fa;
}

int main()
{
	struct flex *fa;




#if 0
	fa = malloc(sizeof(struct flex) + sizeof(int) * count);
	fa->count = count;
#endif
	fa = init_data(100);

	fa->data[0] = 1;
	fa->data[99] = 100;

	printf("%d - %d\n", fa->data[0], fa->data[99]);
}




