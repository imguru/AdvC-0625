#include <stdio.h>
#include <stdlib.h>

// 이중 연결 리스트
// : reverse() 비효율성을 제거할 수 있다.
//  => 역순 검색이나 역순 순회등의 기능을 기존 자료구조의 변경없이
//     수행할 수 있다.

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} NODE;

// 이중 연결리스트에서 삽입에 대한 동작은 prev와 next의 정보만 있다면
// 일반화가 가능하다.
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

#if 0
// s의 노드 뒤에 삽입하는 함수
void insert_back(NODE* s, NODE* temp)
{
	temp->next = s->next;
	s->next = temp;

	temp->prev = s;
	temp->next->prev = temp;
}

// 작성해주세요
void insert_front(NODE* s, NODE* temp)
{
	temp->next = s;
	s->prev->next = temp;

	temp->prev = s->prev;
	s->prev = temp;
}
#endif

void display(NODE* head)
{
	NODE* temp;
	system("clear");
	printf("[head]");

#if 0
	for (temp = head->prev; temp != head ; temp = temp->prev)
	{
		printf("-> [%d]", temp->data);
	}
#endif
#if 1
	for (temp = head->next; temp != head ; temp = temp->next)
	{
		printf("-> [%d]", temp->data);
	}
#endif

	printf("\n");
	getchar();
}

int main()
{
	int i;
	NODE head = { 0, &head, &head };
	NODE nodes[7];
	display(&head);

	for (i = 0; i < 7; ++i)
	{
		nodes[i].data = i + 1;
		insert_back(&head, nodes + i);
		display(&head);
	}

	return 0;
}











