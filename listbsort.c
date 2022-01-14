#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elem { 
    struct elem *next; 
    char *word; 
};

int letter(char x)
{
	if ((x>='a' && x<='z') || (x>='A' && x<='Z'))
		return 1;
	return 0;
}

struct elem *InsertAfter(struct elem *prev,char *word, int j)
{
	struct elem *x=(struct elem*)malloc(1*sizeof(struct elem));
	x->word=(char*)malloc((j+1)*sizeof(char));
	strcpy((*x).word,word);
	(*prev).next=x;
	(*x).next=NULL;
	return x;
}

struct elem *bsort(struct elem *l, struct elem *last)
{
	struct elem *t=last,*prev;
	while (t!=(*l).next)
	{	
		struct elem *bound=t;
		struct elem *i=(*l).next;
		t=(*l).next;
		prev=l;
		while (i !=bound && (*i).next != NULL)
		{
			if(strlen((*i).next->word)<strlen((*i).word))
			{
				struct elem *a,*b;
				(*prev).next=(*i).next;
				a=(*i).next;
				b=(*i).next=i;
				i=a;
				(*b).next=(*a).next;
				(*a).next=b;
				t=i;	
			}
			prev=i;
			i=(*i).next;
		}
	}
	return l;
}
	
int main()
{	
	char s[1000];
	fgets(s,1000,stdin);
	int j=0,len=strlen(s);
	char word[len];
	struct elem *l=(struct elem*)malloc(sizeof(struct elem));
	(*l).next=NULL;
	struct elem *prev=l;
	for(int i=0; i<=len; i++)
	{
		if (letter(s[i]))
			word[j++]=s[i];
		else if (i==0 || letter(s[i-1]))
		{
			word[j]=0;
			prev=InsertAfter(prev,word,j);
			j=0;
		}
	}	
	l=bsort(l,prev);

	struct elem *x=(*l).next,*t;
	while(x!=NULL)
	{	
		t=(*x).next;
		printf("%s ", (*x).word);
		free((*x).word);
		free(x);
		x=t;
	}
	free(l);
}
