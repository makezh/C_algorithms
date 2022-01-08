#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN -2147483648

struct DoubleStack
{
	int *data;
	int cap, top1, top2;
};

void InitQueue(struct DoubleStack *q, int n)
{
	(*q).data = (int *)malloc(sizeof(int) * n);
	(*q).cap = n;
	(*q).top1 = 0;
	(*q).top2 = n - 1;
}

int StackEmpty1(struct DoubleStack q)
{
	return q.top1 == 0;
}

int StackEmpty2(struct DoubleStack q)
{
	return q.top2 == q.cap - 1;
}

void Clear(struct DoubleStack *q)
{
	(*q).cap = 0;
	(*q).top1 = -1;
	(*q).top2 = -1;
	free((*q).data);
	(*q).data = NULL;
}

void Push1(struct DoubleStack *q, int x)
{
	if ((*q).top1 > (*q).top2) printf("Переполнение");
	{
		(*q).data[(*q).top1] = x;
		(*q).top1++;
	}
}

void Push2(struct DoubleStack *q, int x)
{
	if ((*q).top1 > (*q).top2) printf("Переполнение");
	{
		(*q).data[(*q).top2] = x;
		(*q).top2--;
	}
}

int Pop1(struct DoubleStack *q)
{
	(*q).top1--;
	return (*q).data[(*q).top1];
}

int Pop2(struct DoubleStack *q)
{
	(*q).top2++;
	return (*q).data[(*q).top2];
}

void Maximum(struct DoubleStack *q, int *max)
{
	*max = MIN;

	for(int i = 0; i < (*q).top1; i++)
		if (*max < (*q).data[i])
			*max = (*q).data[i];
 
	for(int i = (*q).top2; i <= (*q).cap-1; i++)
		if (*max < (*q).data[i])
			*max = (*q).data[i];

}


void Enqueue(struct DoubleStack *q, int *max, int x)
{
	if (x > *max) *max = x;
	Push1(q, x);
}

int Dequeue(struct DoubleStack *q, int*max)
{
	if(StackEmpty2(*q) != 0)
	{
		while(StackEmpty1(*q) == 0)
		{
			int x = Pop1(q);

			if(x > *max) 
				*max = x;

			Push2(q, x);
		}
	}
	int x = Pop2(q);
	if(x == *max)
		Maximum(q, max);

	return x;
}

int main()
{
	int n;
	scanf("%d", &n);

	int max = MIN;

	struct DoubleStack seq;
	InitQueue(&seq, n+1);

	for(int i = 0; i < n; i++)
	{
		char action[5];
		scanf("%s", action);
		int x;

		if (strcmp(action, "ENQ")==0)
		{
			scanf("%d", &x);
			Enqueue(&seq, &max, x);
		}
		else if (strcmp(action, "DEQ")==0)
		{
			printf("%d\n", Dequeue(&seq, &max));
		}
		else if (strcmp(action, "EMPTY")==0)
		{
			if (StackEmpty1(seq) && StackEmpty2(seq))
				printf("true\n");
			else
				printf("false\n");
		}
		else if (strcmp(action, "MAX")==0)
		{
			printf("%d\n", max);
		}
	}

	Clear(&seq);
	return 0;
}