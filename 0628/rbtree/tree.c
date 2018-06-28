#include <stdio.h>
#include <stdlib.h>

#include "rbtree.h"

// Binary Search Tree - RBTree Example
struct user
{
	char name[32];
	int age;
	int color;
	// ...

	struct rb_node node;
};

struct user* insert_user(struct rb_root *root, struct user* data, struct rb_node* node)
{
	struct rb_node **p = &root->rb_node;
	struct rb_node *parent = NULL;
	struct user *user;

	while (*p)
	{
		parent = *p;
		user = rb_entry(parent, struct user, node);

		if (data->age < user->age) 
			p = &(*p)->rb_left;
		else if (data->age > user->age)
			p = &(*p)->rb_right;
		else
			return user;
	}

	// 삽입 
	rb_link_node(node, parent, p);

	// 컬러 적용
	rb_insert_color(node, root);
}

void __display(struct rb_node *temp, struct user *(*a)[10], int *row, int *col)
{
	struct user* user;
	if (temp == NULL)
		return;

	++*row;
	__display(temp->rb_left, a, row, col);
	
	user = rb_entry(temp, struct user, node);
	user->color = rb_color(temp);

	a[*row][(*col)++] = user;

	__display(temp->rb_right, a, row, col);
	--*row;

	return;
}

void display(struct rb_root *root)
{
	struct user *a[10][10] = {0, };
	int row = -1;
	int col = 0;
	int i, j;

	__display(root->rb_node, a, &row, &col); 
	system("clear");

	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			if (a[i][j] != NULL)
			{
				if (a[i][j]->color)  // Black
				{
					printf("[%s(%d)]", a[i][j]->name, a[i][j]->age);
				}
				else                // Red
				{
					printf("<%s(%d)>", a[i][j]->name, a[i][j]->age);
				}
			}
			else
				printf("%8c", ' ');
		}
		printf("\n");
	}

	getchar();
}


int main()
{
	struct user users[8] = {
		{ .name = "Tom", .age = 5 },
		{ .name = "Tom", .age = 6 },
		{ .name = "Tom", .age = 7 },
		{ .name = "Tom", .age = 8 },
		{ .name = "Tom", .age = 9 },
		{ .name = "Tom", .age = 10 },
		{ .name = "Tom", .age = 11 },
		{ .name = "Tom", .age = 12 },
	};

	struct rb_root root = { 0, };
	int i;

	for (i = 0; i < 8; i++)
	{
		insert_user(&root, &users[i], &users[i].node);
		display(&root);
	}

	return 0;
}
