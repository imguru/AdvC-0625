// C언어에서 연결리스트를 구현하는 방법
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE;

NODE head;

// s의 노드 뒤에 새로운 노드를 삽입한다.
void insert_node(NODE* s, int data)
{
	NODE* temp = malloc(sizeof(NODE));
	temp->data = data;

	temp->next = s->next;
	s->next = temp;
}

void display()
{
	NODE* temp;
	system("clear");
	printf("[head]");

	for (temp = head.next; temp != NULL ; temp = temp->next)
	{
		printf("-> [%d]", temp->data);
	}

	printf("\n");
	getchar();
}



int main()
{
	int i;
	display();

	for (i = 0; i < 7; ++i)
	{
		insert_node(&head, i + 1);
		display();
	}

	return 0;
}











