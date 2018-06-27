// C언어에서 연결리스트를 구현하는 방법
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE;

// 연결리스트의 head를 전역 변수로 만들면 프로그램에 하나의 연결리스트만
// 만들 수 밖에 없다.
// NODE head = { 0, &head };

void insert_node(NODE* s, NODE* temp)
{
	temp->next = s->next;
	s->next = temp;
}

void display(NODE* head)
{
	NODE* temp;
	system("clear");
	printf("[head]");

	for (temp = head->next; temp != head ; temp = temp->next)
	{
		printf("-> [%d]", temp->data);
	}

	printf("\n");
	getchar();
}



int main()
{
	int i;
	NODE head = { 0, &head };
	NODE nodes[7];
	// 사용자가 원하는 메모리 영역을 연결 리스트로 구성하는 것이
	// 가능하다.

	display(&head);

	for (i = 0; i < 7; ++i)
	{
		nodes[i].data = i + 1;
		insert_node(&head, nodes + i);
		display(&head);
	}

	return 0;
}











