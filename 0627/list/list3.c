// C언어에서 연결리스트를 구현하는 방법
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE;

NODE tail = { 0, &tail };
NODE head = { 0, &tail };
// 연결리스트에서 가장 많이 발생하는 문제
//  => 잘못된 메모리 참조(Null 참조)
//  => tail 이라는 더미 노드를 통해서 끝에 도달하더라도 널 참조의
//     가능성을 없애자.

//  문제점
//   : head의 더미노드가 tail의 역활을 수행할 수 있다.
//   => 환형 연결 리스트


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

	for (temp = head.next; ; temp = temp->next)
	// for (temp = head.next; temp != &tail ; temp = temp->next)
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











