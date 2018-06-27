// C언어에서 연결리스트를 구현하는 방법
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE;

NODE* head;

void insert_node(int data)
{
	NODE* temp = malloc(sizeof(NODE));
	temp->data = data;

	temp->next = head;
	head = temp;
}

void display()
{
	NODE* temp;
	system("clear");
	printf("[head]");

	for (temp = head; temp != NULL ; temp = temp->next)
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
		insert_node(i + 1);
		display();
	}

	return 0;
}











