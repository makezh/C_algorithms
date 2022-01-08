#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int cap;
	int top;
	int *data;
};

void InitStack(struct Stack *s, int n)
{
	(*s).data = (int*)malloc(sizeof(int) * n);
	(*s).cap = n;
	(*s).top = 0;
}

int StackEmpty(struct Stack s)
{
	return s.top == 0;
}

void Push(struct Stack *s, int x)
{
	if ((*s).top == (*s).cap) printf("Переполнение");
	else
	{
	(*s).data[(*s).top] = x;
	(*s).top++;
	}
}

int Pop(struct Stack *s)
{
	(*s).top--;
	return (*s).data[(*s).top];
	
}

int main()
{
	int n;
	scanf("%d", &n);
	struct Stack stack;
	InitStack(&stack, n);

	for(int i = 0; i < n; i++)
	{
		char action[6];
		scanf("%s", action);

		int a, b, x;

		if (strcmp(action, "CONST") == 0)
		{
			scanf("%d", &x);
			Push(&stack, x);
		}
		else if (strcmp(action, "ADD") == 0)
		{
			a = Pop(&stack);
			b = Pop(&stack);
			Push(&stack, a + b);
		}
		else if (strcmp(action, "SUB") == 0)
		{
			a = Pop(&stack);
			b = Pop(&stack);
			Push(&stack, a - b);
		}
		else if (strcmp(action, "MUL") == 0)
		{
			a = Pop(&stack);
			b = Pop(&stack);
			Push(&stack, a * b);
		}
		else if (strcmp(action, "DIV") == 0)
		{
			a = Pop(&stack);
			b = Pop(&stack);
			Push(&stack, a / b);
		}
		else if (strcmp(action, "MAX") == 0)
		{
			a = Pop(&stack);
			b = Pop(&stack);
			if(a > b)
				Push(&stack, a);
			else
				Push(&stack, b);
		}
		else if (strcmp(action, "MIN") == 0)
		{
			a = Pop(&stack);
			b = Pop(&stack);
			if(a < b)
				Push(&stack, a);
			else
				Push(&stack, b);
		}
		else if (strcmp(action, "NEG") == 0)
		{
			a = Pop(&stack);
			Push(&stack, -a);
		}
		else if (strcmp(action, "DUP") == 0)
		{
			a = Pop(&stack);	
			Push(&stack, a);
			Push(&stack, a);
		}
		else if (strcmp(action, "SWAP") == 0)
		{
			a = Pop(&stack);
			b = Pop(&stack);
			Push(&stack, a);
			Push(&stack, b);
		}

	}
	printf("%i\n", Pop(&stack));
	free(stack.data);
}