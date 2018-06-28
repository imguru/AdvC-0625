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
	insert_data(1, root, LEFT);  // root!
	display(root);
	insert_data(2, root, LEFT);
	display(root);
	insert_data(3, root, RIGHT);
	display(root);

	insert_data(4, root->left, LEFT);
	display(root);
	insert_data(5, root->left, RIGHT);
	display(root);
	
	insert_data(6, root->right, LEFT);
	display(root);
	insert_data(7, root->right, RIGHT);
	display(root);
}

























