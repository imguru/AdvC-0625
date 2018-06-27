#include <stdio.h>
#include <stdlib.h>

// struct list_head
// task_struct
typedef struct node
{
	struct node *next;
	struct node *prev;
} NODE;

typedef struct {
	char name[32];
	int a;
	int b;
	int c;

	NODE links;
} USER;

void __insert_data(NODE* prev, NODE* next, NODE* temp)
{
	temp->next = next;
	temp->prev = prev;
	prev->next = temp;
	next->prev = temp;
}

void insert_back(NODE* s, NODE* temp)
{
	__insert_data(s, s->next, temp);
}

void insert_front(NODE* s, NODE* temp)
{
	__insert_data(s->prev, s, temp);
}

#define offsetof(type, member)	(size_t)&(((type*)0)->member)
#define container_of(ptr, type, member) 	\
	(type *)((char *)ptr - offsetof(type, member))

void display(NODE* head)
{
	NODE* temp;
	system("clear");
	printf("[head]");

	for (temp = head->next; temp != head ; temp = temp->next)
	{
		// USER *user = (USER*)((char*)temp - offsetof(USER, links));
		USER* user = container_of(temp, USER, links);
		printf("-> [%s]", user->name);
	}

	printf("\n");
	getchar();
}

int main()
{
	int i;
	NODE head = { &head, &head };

	USER users[3] = { { .name = "홍길동"}, { .name = "강감찬"}, { .name = "이순신"} };

	display(&head);

	for (i = 0; i < 3; ++i)
	{
		insert_back(&head, &users[i].links);   // !!!
		display(&head);
	}

	return 0;
}








