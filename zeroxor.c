#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PANIC break


struct Node
{
    int k, v;
    struct Node *parent, *left, *right;
};

struct Tree
{
    struct Node *root;
};

struct Node *FindNode(struct Tree *tree, int key)
{
    struct Node *node  = (*tree).root;

    for(;node != NULL && (*node).k != key;)
    {
        if(key >= (*node).k) node = (*node).right;
        else node = (*node).left;
    }

    return node;
}

struct Node *Insert(struct Tree *tree, int key, int value)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));

    (*NewNode).k = key;
    (*NewNode).v = value;
    (*NewNode).parent = (*NewNode).left = (*NewNode).right = NULL; 
    if((*tree).root == 0)
    {
        (*tree).root = NewNode;
        return (*tree).root;
    }

    struct Node *node = (*tree).root;
    while(1)
    {
        if(key >= (*node).k)
        {
					if((*node).right == 0)
          {
            (*node).right = NewNode;
            (*NewNode).parent = node;
            PANIC;
          }
          node = (*node).right;
        }
        else 
        {
					if((*node).left == 0) 
          {
          	(*node).left = NewNode;
          	(*NewNode).parent = node;
          	PANIC;
          }
          node = (*node).left;
        }

    }

    return NewNode;
}

void ClearNode(struct Node *node)
{
    if((*node).left) ClearNode((*node).left);

    if((*node).right) ClearNode((*node).right);

    free(node);
}

void Clear(struct Tree tree)
{
    if(tree.root)
      ClearNode(tree.root);
}

int main()
{
    int n, i = 0, s = 0;
		long long k = 0;
    scanf("%d", &n);

    struct Tree tree;
    tree.root = NULL;

		while (i < n)
		{
        int x;
        scanf("%d", &x); 
        s ^= x;

        struct Node *node = FindNode(&tree, s);

        if(!node) 
					node = Insert(&tree, s, 0);

        (*node).v++;

        if(s == 0) 
					k += (*node).v; 
        else 
					k += (*node).v - 1;

				i++;
    }

    printf("%lld\n", k);
    
    Clear(tree);
}