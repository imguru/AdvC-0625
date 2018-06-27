#include <stdio.h>
#include <stdlib.h>

struct list_head {
	struct list_head *next, *prev;
};

typedef struct {
	char name[32];

	struct list_head links;
} USER;

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

#define offsetof(TYPE, MEMBER)	((size_t)&((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
	(type *)( (char *)__mptr - offsetof(type,member) );})

static inline void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}

#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

#define list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)

void display(struct list_head* head)
{
	struct list_head* temp;

	system("clear");
	printf("[head]");

	list_for_each(temp, head)
	{
		USER* u = container_of(temp, USER, links);
		printf(" -> [%s]", u->name);
	}

#if 0
	for (temp = head->next; temp != head ; temp = temp->next)
	{
		USER* u = container_of(temp, USER, links);
		printf(" -> [%s]", u->name);
	}
#endif

	printf("\n");
	getchar();
}

int main()
{
	int i;
	USER users[3] = { { .name = "강감찬" }, { .name = "이순신" }, { .name = "홍길동" } };
	
	// struct list_head head = { &head, &head };
	LIST_HEAD(head);
	display(&head);

	for (i = 0 ; i < 3; ++i)
	{
		list_add(&users[i].links, &head);
		display(&head);
	}

	return 0;
}
