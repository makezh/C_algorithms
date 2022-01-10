#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct elem {
    int k,count;
		struct elem *parent,*left,*right;
		char *v;
	};
struct elem *minimum(struct elem *t)
{
	if (t==NULL)
		return NULL;
	else
	{
		struct elem *x=t;
		while (x->left!=NULL)
			x=x->left;
		return x;
	}
}
struct elem *succ(struct elem *x)
{
	if(x->right!=NULL)
		return minimum(x->right);
	else
	{
		struct elem *y=x->parent;
		while (y!=NULL && x==y->right)
		{
			x=y;
			y=y->parent;
		}
		return y;
	}
}
struct elem *descend(struct elem *t, int k)
{
	struct elem *x=t;
	while (x!=NULL && x->k!=k)
	{
		if (k<x->k)
			x=x->left;
		else
			x=x->right;
	}
	return x;
}
char *lookup(struct elem *t, int k)
{
	return descend(t,k)->v;	
}
void init(struct elem *y, int k, char *v)
{	
	y->v=(char*)malloc(10*sizeof(char));
	y->k=k;
	strcpy(y->v,v);
	y->parent=NULL;
	y->left=NULL;
	y->right=NULL;
}
struct elem *insert(struct elem *t, int k, char *v)
{
	struct elem *y=(struct elem*)malloc(1*sizeof(struct elem));
	init(y,k,v);
	if (t==NULL)
		t=y;
	else
	{	
		struct elem *x;
		x=t;
		for(;;)
		{
			if (k<x->k)
			{
				if(x->left ==NULL)
				{
					x->left=y;
					y->parent=x;
					break;
				}
				x=x->left;
			}
			else
			{
				if(x->right ==NULL)
				{
					x->right=y;
					y->parent=x;
					break;
				}
				x=x->right;
			}
		}
	}
	return t;
}	
struct elem *replace(struct elem *t, struct elem *x, struct elem *y)
{
	if (x==t)
	{
		t=y;
		if (y!=NULL)
			y->parent=NULL;
	}
	else
	{
		struct elem *p;
		p=x->parent;
		if (y!=NULL)
			y->parent=p;
		if (p->left == x)
			p->left=y;
		else
			p->right=y;
	}
	return t;
}
struct elem *delete(struct elem *t, int k)
{
	struct elem *x=descend(t,k);
	if (x->left==NULL && x->right==NULL)
		t=replace(t,x,NULL);
	else if (x->left==NULL)
		t=replace(t,x,x->right);
	else if(x->right==NULL)
		t=replace(t,x,x->left);
	else
	{
		struct elem *y=succ(x);
		t=replace(t,y,y->right);
		x->left->parent=y;
		y->left=x->left;
		if(x->right!=NULL)
			x->right->parent=y;
		y->right=x->right;
		t=replace(t,x,y);
	}
	free(x->v);
	free(x);
	return t;
}
void my_free(struct elem *left, struct elem *right)
{	
	if (right !=NULL)
	{	
		free(right->v);
		my_free(right->right,right->left);
		free(right);
	}
	if (left!=NULL)
	{	
		free(left->v);
		my_free(left->left,left->right);
		free(left);
	}
}
char *search(struct elem *list, int k)
{
	struct elem *x=minimum(list);
	int i=0;
	while(i!=k)
	{
		x=succ(x);
		++i;
	}
	return x->v;
}
int main()
{
	int i,n,j,k,m;
	char com[10],str[10];
	struct elem *list;
	list=NULL;
	scanf("%d", &n);
	for(i=0;i<n;++i)
	{
		scanf("%s %d", com, &k);
		if (com[0]=='I')
		{
			scanf("%s", str);
			list=insert(list,k,str);
		}
		else if(com[0]=='L')
		{	
			printf("%s\n", lookup(list,k));
		}
		else if(com[0]=='D')
		{	
			list=delete(list,k);
		}
		else
			printf("%s\n", search(list,k));
	}
	struct elem *left=list->left,*right=list->right;
	my_free(left,right);
	free(list->v);
	free(list);
}
