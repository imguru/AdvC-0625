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


void display(struct node *temp)
{
	static int indent = -1;
	if (temp == NULL)
		return;

	++indent;
	display(temp->right);
	printf("%*d\n", indent * 4, temp->data);
	display(temp->left);
	--indent;
}

int main()
{
	insert_data(1, root, LEFT);  // root!
	// display(root);
	insert_data(2, root, LEFT);
	// display(root);
	insert_data(3, root, RIGHT);
	// display(root);

	insert_data(4, root->left, LEFT);
	// display(root);
	insert_data(5, root->left, RIGHT);
	// display(root);
	
	insert_data(6, root->right, LEFT);
	// display(root);
	insert_data(7, root->right, RIGHT);
	display(root);
}

























