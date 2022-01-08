#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue
{
	int *data;
	int cap, count, head, tail;
};

void InitQueue(struct Queue *q, int n)
{
	(*q).data = (int *)malloc(sizeof(int) * n);
	(*q).cap = n;
	(*q).count = 0;
	(*q).head = 0;
	(*q).tail = 0;
}

int QueueEmpty(struct Queue q)
{
	return q.count == 0;
}

void Enqueue(struct Queue *q, int x)
{
	if ((*q).count == (*q).cap) printf("Переполнение");
	else
	{
		(*q).data[(*q).tail] = x;
		(*q).tail++;

		if((*q).tail == (*q).cap)
		{
			(*q).cap *= 2;
			(*q).data = (int *)realloc((*q).data, sizeof(int) * (*q).cap);
		}

		(*q).count++;
	}
}

int Dequeue(struct Queue *q)
{
	int x = (*q).data[(*q).head];
	(*q).head++;

	if((*q).head == (*q).cap) 
		(*q).head = 0;

	(*q).count--;

	return x;
}

int main()
{
	int n;
	scanf("%d", &n);

	struct Queue seq;
	InitQueue(&seq, 4);

	for(int i = 0; i < n; i++)
	{
		char action[5];
		scanf("%s", action);
		int x;

		if (strcmp(action, "ENQ")==0)
		{
			scanf("%d", &x);
			Enqueue(&seq, x);
		}
		else if (strcmp(action, "DEQ")==0)
		{
			printf("%d\n", Dequeue(&seq));
		}
		else if (strcmp(action, "EMPTY")==0)
		{
			if (QueueEmpty(seq))
				printf("true\n");
			else
				printf("false\n");
		}
	}

	free(seq.data);
	return 0;
}