#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 100000
#define NEXT continue
#define STOP break

struct Elem {
    struct Elem *next;
    char *word;
};


int Compare(struct Elem *x, struct Elem *y)
{
	if (strlen((*x).word) > strlen((*y).word)) return 1;
	else if (strlen((*x).word) < strlen((*y).word)) return -1;
	else return 0;
}

int Len(struct Elem *head) 
{
	int len = 0;
	for(struct Elem *el = head; el != NULL; el = (*el).next, len++);
	return len;
}

struct Elem *bsort(struct Elem *head)
{
    struct Elem *elem = head, *i, *tail = NULL;
		while (elem != NULL && (*elem).next != tail)
		{
        i = elem;

				while ((*i).next->next != tail)
				{
            if(strlen((*i).next->word) < strlen((*i).next->next->word))
						{
                struct Elem *tmp = (*i).next, *t = (*i).next->next->next;
                (*i).next = (*i).next->next;
                (*i).next->next = tmp;
                (*i).next->next->next = t;
            }

					i = (*i).next;
        }

			tail = (*i).next;
    }

    return head;
}

void PrintList(struct Elem *list){
    if(list->next != NULL) 
			PrintList((*list).next);
    printf("%s ", (*list).word);
    free((*list).word);
    free(list);
}


int main()
{
	struct Elem *head = (struct Elem *)malloc(sizeof(struct Elem));
    (*head).next = NULL;
		
	char c = '0', sep = ' ', end='\n';

  while (c != end) 
	{
    int k = 0;

		char *word = malloc(STRLEN * sizeof(char));
    scanf("%c", &c);

    if(c == end)
		{
        free(word);
        STOP;
    }

    while (c != end && c != sep) {
        word[k] = c;
				k++;
        scanf("%c", &c);
    }

    word[k] = '\0';
    if(word[0] == '\0')
		{
      free(word);
      NEXT;
    }

    struct Elem *elem = (struct Elem *)malloc(sizeof(struct Elem));

    (*elem).next = (*head).next;
    (*elem).word = word;
    (*head).next = elem;
    }
	head = bsort(head);

	PrintList(head->next);
	printf("\n");
	free(head);
}