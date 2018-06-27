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


// s의 노드 뒤에 삽입하는 함수
void insert_node(NODE* s, NODE* temp)
{
	temp->next = s->next;
	s->next = temp;

	temp->prev = s;
	temp->next->prev = temp;
}

void display(NODE* head)
{
	NODE* temp;
	system("clear");
	printf("[head]");

	for (temp = head->prev; temp != head ; temp = temp->prev)
	{
		printf("-> [%d]", temp->data);
	}
#if 0
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
		insert_node(&head, nodes + i);
		display(&head);
	}

	return 0;
}











