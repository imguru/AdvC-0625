#include <stdio.h>
#include <stdlib.h>

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

// 1. prev가 필요하냐?
// 2. root가 null일 때와 아닐 때의 코드가 분리되어 있다.
// 3. 루프 밖에서 조건 비교를 한번 더 수행한다.
#if 0
void insert_data(int data)
{
	struct node *temp;
	struct node *p = root, *prev = NULL;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	// 첫번째 노드인 경우
	if (root == NULL)
	{
		root = temp;
		return;
	}

	// 두번째 이상부터는 
	while (p)
	{
		prev = p;
		if (p->data > data)
			p = p->left;
		else if (p->data < data)
			p = p->right;
		else
			return;               // 이미 키가 존재한다.
	}

	if (prev->data > data)
		prev->left = temp;
	else 
		prev->right = temp;
}
#endif

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

int main()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 7 };
	int i;

	display(root);

	for (i = 0 ; i < 7 ; ++i)
	{
		insert_data(a[i]);
		// insert_data( i + 1 );
		display(root);
	}
	return 0;
}

// Hash -> 충돌 -> 연결법
// Tree -> 사향 트리 



















