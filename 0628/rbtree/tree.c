#include <string.h>
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

#if 0
static inline struct page * rb_search_page_cache(struct inode * inode,
		unsigned long offset)
{
	struct rb_node * n = inode->i_rb_page_cache.rb_node;
	struct page * page;

	while (n)
	{
		page = rb_entry(n, struct page, rb_page_cache);

		if (offset < page->offset)
			n = n->rb_left;
		else if (offset > page->offset)
			n = n->rb_right;
		else
			return page;
	}
	return NULL;
}
#endif
struct user *search_user(struct rb_root *root, char* name)
{
	struct rb_node *p = root->rb_node;
	struct user *user;
	
	while (p)
	{
		user = rb_entry(p, struct user, node);
		if (strcmp(name, user->name) < 0)
			p = p->rb_left;
		else if (strcmp(name, user->name) > 0)
			p = p->rb_right;
		else
			return user;
	}

	return NULL;
}

struct user* insert_user(struct rb_root *root, struct user* data, struct rb_node* node)
{
	struct rb_node **p = &root->rb_node;
	struct rb_node *parent = NULL;
	struct user *user;

	while (*p)
	{
		parent = *p;
		user = rb_entry(parent, struct user, node);

		if (strcmp(data->name, user->name) < 0)
			p = &(*p)->rb_left;
		else if (strcmp(data->name, user->name) > 0)
			p = &(*p)->rb_right;
		else
			return user;

#if 0
		if (data->age < user->age) 
			p = &(*p)->rb_left;
		else if (data->age > user->age)
			p = &(*p)->rb_right;
		else
			return user;
#endif
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
		{ .name = "손흥민", .age = 5 },
		{ .name = "박지성", .age = 6 },
		{ .name = "최용수", .age = 7 },
		{ .name = "장현수", .age = 8 },
		{ .name = "조현우", .age = 9 },
		{ .name = "이용", .age = 10 },
		{ .name = "홍철", .age = 11 },
		{ .name = "기성용", .age = 12 },
	};

	struct rb_root root = { 0, };
	int i;
	struct user* p;

	for (i = 0; i < 8; i++)
	{
		insert_user(&root, &users[i], &users[i].node);
		display(&root);
	}

	p = search_user(&root, "홍철");
	if (p == NULL)
	{
		printf("찾지 못하였습니다...\n");
	}
	else
	{
		printf("%s - %d\n", p->name, p->age);
	}

	return 0;
}










