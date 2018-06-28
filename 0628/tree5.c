#include <stdio.h>
#include <stdlib.h>

// 트리의 노드의 삽입 또는 삭제가 발생할 때
// 불균형이 발생한다면, 스스로 균형잡는 알고리즘

// => AVL Tree
//   : 카운트 기반
//    => 왼쪽 자식의 개수와 오른쪽 자식의 개수가 특정 값 이상이면
//       불균형으로 판단한다.

// => RB  Tree
//   : 상태 머신 기반
//    => 모든 노드는 검은색 또는 빨간색이다.
//       부모노드와 자식 노드가 둘 다 빨간색이면 불균형이다.

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root;

void insert_data(int data)
{
	struct node *temp;
	struct node **p = &root;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	while ( *p )
	{
		if ((*p)->data > data)
			p = &(*p)->left;
		else if ((*p)->data < data) 
			p = &(*p)->right;
		else
			return;
	}

	*p = temp;
}

void __display(struct node *temp, int (*a)[10], int *row, int *col)
{
	if (temp == NULL)
		return;

	++*row;
	__display(temp->left, a, row, col);
	a[*row][(*col)++] = temp->data;
	__display(temp->right, a, row, col);
	--*row;

	return;
}

void display(struct node *temp)
{
	int a[10][10] = { 0, };
	int row = -1;
	int col = 0;
	int i, j;

	__display(temp, a, &row, &col); 
	system("clear");

	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			if (a[i][j] != 0)
				printf("%4d", a[i][j]);
			else
				printf("%4c", ' ');
		}
		printf("\n");
	}

	getchar();
}

void __fill(struct node *temp, int *a, int *n)
{
	if (temp == NULL)
		return;

	__fill(temp->left, a, n);
	a[(*n)++] = temp->data;
	__fill(temp->right, a, n);
}

struct node*  __bal(int *a, int n)
{
	int mid = n / 2;
	struct node *temp;

	// 기저조건
	if (n < 1)
		return NULL;

	temp = malloc(sizeof(struct node));
	temp->data = a[mid];
	temp->left = __bal(a, mid);
	temp->right = __bal(a + mid + 1, n - mid - 1);

	return temp;
}

void balance(struct node *temp)
{
	int a[100] = {0, };
	int n = 0;

	// 1. 배열에 트리의 모든 노드를 채운다. - 정렬된 형태
	__fill(temp, a, &n);
	root = __bal(a, n);
}

int main()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 7 };
	int i;

	display(root);

	for (i = 0 ; i < 7 ; ++i)
	{
		// insert_data(a[i]);
		insert_data( i + 1 );
		display(root);
	}

	balance(root);
	display(root);

	return 0;
}
