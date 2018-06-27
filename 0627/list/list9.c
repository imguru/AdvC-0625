#include <stdio.h>
#include <stdlib.h>

// 데이터에 대한 일반화를 해보자.
// -> void*

// 문제점?
// => void 포인터를 통해서 데이터를 별도로 관리하기 때문에
//    메모리 관리에 대한 부담이 크다.
//   1) 메모리 누수의 위험성이 크다.
//   2) 성능 - 캐시 적중률도 낮다.
//   3) data는 오직 한개의 연결리스트에만 연결이 가능하다.

// 해결 방법
// => 연결리스트가 데이터를 가지고 있는 것이 아니라,
//    데이터가 연결리스트를 가지고 있어야 한다.

typedef struct node
{
	void* data;
	struct node *next;
	struct node *prev;
} NODE;

typedef struct {
	char name[32];
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
		USER *user = temp->data;
		printf("-> [%s]", user->name);
	}

	printf("\n");
	getchar();
}

int main()
{
	int i;
	NODE head = { 0, &head, &head };

	NODE nodes[3];
	USER users[3] = { {"홍길동"}, {"강감찬"}, {"이순신"} };

	display(&head);

	for (i = 0; i < 3; ++i)
	{
		nodes[i].data = users + i;
		insert_back(&head, nodes + i);
		display(&head);
	}

	return 0;
}








