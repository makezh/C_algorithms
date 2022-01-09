#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Elem
{
	struct Elem *prev, *next;
	int v;
} ;

void InsertAfter(struct Elem *x, struct Elem *y)
{
	struct Elem *z;
	z = (*x).next;
	(*x).next = y;
	(*y).prev = x;
	(*y).next = z;
	(*z).prev = y;
}

void Delete(struct Elem *x)
{
	struct Elem *y, *z;
	y = (*x).prev;
	z = (*x).next;
	(*y).next = z;
	(*z).prev = y;

	(*x).prev = NULL;
	(*x).next = NULL;
}

void InsertSort(struct Elem *head)
{
	struct Elem *i, *loc;
	i = (*head).next;

	while (i != head)
	{
		loc = (*i).prev;

		while ((loc != head) && ((*loc).v > (*i).v))
			loc = (*loc).prev;

		Delete(i);

		InsertAfter(loc, i);
		i = (*i).next;
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	struct Elem *head = (struct Elem*)malloc(sizeof(struct Elem)), *elem;

	(*head).next = head;
	(*head).prev = head;

	for (int i = 0; i < n; i++)
	{
		elem = (struct Elem*)malloc(sizeof(struct Elem));
		scanf("%d", &((*elem).v));
		InsertAfter(head, elem);
	}

	InsertSort(head);

	elem = head->next;
	while (elem != head)
	{
		printf("%d ", (*elem).v);
		struct Elem *prev = elem;
		elem = (*elem).next;
		free(prev);
	}
	printf("\n");
	free(head);
	return 0;
}