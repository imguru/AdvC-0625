// C언어에서 연결리스트를 구현하는 방법
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE;

NODE head = { 0, &head };
// s의 노드 뒤에 새로운 노드를 삽입한다.

// 아래와 같이 함수를 만들때 문제점
// 1. 삽입 로직의 성능이 저하된다.
// 2. 노드의 메모리는 사용자가 원하는 영역에 할당될 수 있어야 한다.

// => 노드 할당에 대한 로직과 삽입에 대한 로직은 반드시 분리되어야 한다.
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

	// for (temp = head.next; temp != &head ; temp = temp->next)
	for (temp = head.next; ; temp = temp->next)
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











