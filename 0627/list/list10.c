#include <stdio.h>
#include <stdlib.h>

// 해결 방법
// => 연결리스트가 데이터를 가지고 있는 것이 아니라,
//    데이터가 연결리스트를 가지고 있어야 한다.

typedef struct node
{
	struct node *next;
	struct node *prev;
} NODE;

typedef struct {
	char name[32];

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

void display(NODE* head)
{
	NODE* temp;
	system("clear");
	printf("[head]");

	for (temp = head->next; temp != head ; temp = temp->next)
	{
		// 핵심!
		USER *user = (USER*)((char*)temp - (sizeof(USER) - sizeof(NODE)));
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








