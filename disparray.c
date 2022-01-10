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

struct Hash
{
	struct Tree *table;
	int size;
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

void InitHashTable(struct Hash *t, int size)
{
	(*t).size = size;
	(*t).table = (struct Tree *)malloc(sizeof(struct Tree) * size);
	for(int i = 0; i < size; i++) 
	{
		struct Tree tree;
		tree.root = NULL;
		(*t).table[i] = tree;
	}
}

void HClear(struct Hash t)
{
	for(int i = 0; i < t.size; i++) 
		Clear(t.table[i]);
	free(t.table);
}

void Assign(struct Hash *t, int key, int value)
{
	int i = key % (*t).size;
	struct Tree *tree = &(*t).table[i];
	struct Node *node = FindNode(tree, key);

	if(!node) 
		Insert(tree, key, value);
  else 
		(*node).v = value;
}

int At(struct Hash *t, int key)
{
	int i = key % (*t).size;
	struct Tree *tree = &(*t).table[i];
	struct Node *node = FindNode(tree, key);

	if(node) 
		return (*node).v;
	else
		return 0;
}

int main()
{
  int n, m, i = 0;
  scanf("%d %d", &n, &m);
  struct Hash table;

  InitHashTable(&table, m);
	
	while (i < n)
	{
    char action[6];
    scanf("%s", action);

		int key;
    if(strcmp(action, "ASSIGN") == 0)
    {
			int val;
      scanf("%d %d", &key, &val);
      Assign(&table, key, val);
    }
    else if(strcmp(action, "AT") == 0)
    {
      scanf("%d", &key);
      printf("%d\n", At(&table, key));
    }
		i++;
  }
	
  HClear(table);
}