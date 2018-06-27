// C언어에서 연결리스트를 구현하는 방법
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE;

NODE head = { 0, &head };

void insert_node(NODE* s, NODE* temp)
{
	temp->next = s->next;
	s->next = temp;
}

void display()
{
	NODE* temp;
	system("clear");
	printf("[head]");

	for (temp = head.next; temp != &head ; temp = temp->next)
	{
		printf("-> [%d]", temp->data);
	}

	printf("\n");
	getchar();
}



int main()
{
	int i;
	NODE nodes[7];
	// 사용자가 원하는 메모리 영역을 연결 리스트로 구성하는 것이
	// 가능하다.

	display();

	for (i = 0; i < 7; ++i)
	{
		nodes[i].data = i + 1;
		insert_node(&head, nodes + i);
		display();
	}

	return 0;
}











