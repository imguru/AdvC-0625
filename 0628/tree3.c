#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root;

typedef enum { LEFT, RIGHT } FLAG;

void insert_data(int data, struct node *s, FLAG flag)
{
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	// root가 NULL인 경우에 대해서 반드시 처리해야 한다.
	if (root == NULL)
	{
		root = temp;
		return;
	}


	if (flag == LEFT)
		s->left = temp;
	else
		s->right = temp;
}

//           1
//      2          3
//   4    5     6      7


void preorder(struct node *temp)
{
	if (temp == NULL)
		return;

	printf("%3d", temp->data);
	preorder(temp->left);
	preorder(temp->right);
}


void inorder(struct node *temp)
{
	if (temp == NULL)
		return;

	inorder(temp->left);
	printf("%3d", temp->data);
	inorder(temp->right);
}

void postorder(struct node *temp)
{
	if (temp == NULL)
		return;

	postorder(temp->left);
	postorder(temp->right);
	printf("%3d", temp->data);
}


#if 0
int (*__display(struct node *temp))[10]
{
	static int a[10][10] = { 0, };
	static int col = 0;
	static int row = -1;

	if (temp == NULL)
		return a;

	++row;
	__display(temp->left);
	a[row][col++] = temp->data;
	__display(temp->right);
	--row;

	return a;
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

























