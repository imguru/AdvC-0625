// C언어에서 연결리스트를 구현하는 방법
#include <stdio.h>
#include <stdlib.h>


// 문제점: head가 포인터이기 때문에, 
//         head에 삽입하는 코드와 특정 노드의 뒤에 삽입하는 코드의
//         로직이 동일함에도 불구하고,
//         다른 함수로 제공해야 한다.

// head를 포인터로 하지 말고 더미 노드로 하자.
//   => 특정 노드 뒤에 삽입하는 로직을 하나의 함수로 일반화가 가능하다.


typedef struct node
{
	int data;
	struct node *next;
} NODE;

NODE* head;

// s의 노드 뒤에 새로운 노드를 삽입한다.
void insert_node2(NODE* s, int data)
{
	NODE* temp = malloc(sizeof(NODE));
	temp->data = data;

	temp->next = s->next;
	s->next = temp;
}

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











