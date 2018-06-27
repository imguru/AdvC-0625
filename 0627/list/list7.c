#include <stdio.h>
#include <stdlib.h>

// 단일 연결리스트에서 역순 검색을 할 수 있는가?
typedef struct node
{
	int data;
	struct node *next;
} NODE;

void reverse(NODE* head)
{
	NODE *prev = head;
	NODE *curr, *next;
	
	curr = prev->next;
	while (curr != head) 
	{
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}

	head->next = prev;
}

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

	reverse(&head);
	display(&head);

	return 0;
}











