#include <stdio.h>
#include <stdlib.h>


int scanmas(int mas[], int n)
{
	for(int i = 0; i < n; i++)
		scanf("%d", &mas[i]);
	return *mas;
}

void printmas(int mas[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", mas[i]);
		if (i == n-1) printf("\n");
	}
}

struct Task
{
	int low, high;
};

struct Stack
{
	int cap;
	int top;
	struct Task *data;
};

void InitStack(struct Stack *s, int n)
{
	(*s).data = (struct Task *)malloc(sizeof(struct Task) * n);
	(*s).cap = n;
	(*s).top = 0;
}

int StackEmpty(struct Stack s)
{
	return s.top == 0;
}

void Push(struct Stack *s, struct Task x)
{
	if ((*s).top == (*s).cap) printf("Переполнение");
	else
	{
	(*s).data[(*s).top] = x;
	(*s).top++;
	}
}

struct Task Pop(struct Stack *s)
{
	(*s).top--;
	return (*s).data[(*s).top];
	
}

int Partition(int mas[], int left, int right)
{
	int i = left, j = left;
	while (j < right)
	{
		if (mas[j] < mas[right])
		{
			int tmp = mas[j];
			mas[j] = mas[i];
			mas[i] = tmp;
			i++;
		}
		j++;
	}
	int tmp = mas[i];
	mas[i] = mas[right];
	mas[right] = tmp;
	
	return i;
}

void QuicksortStack(int mas[], int n)
{
	struct Stack seq;
	InitStack(&seq, n);

	struct Task init_task;

	init_task.low = 0;
	init_task.high = n - 1;

	Push(&seq, init_task);

	while(!StackEmpty(seq))
	{
		struct Task task = Pop(&seq);

		int left = task.low, right = task.high;

		if(left < right)
		{
			struct Task newTask;
			int q = Partition(mas, left, right);

			newTask.low = left;
			newTask.high = q - 1;
			Push(&seq, newTask);
			
			newTask.low = q + 1;
			newTask.high = right;
			Push(&seq, newTask);
		}
	}
	free(seq.data);
}

int main()
{
	int n;
	scanf("%d", &n);
	int nums[n];

	*nums = scanmas(nums, n);
	
	QuicksortStack(nums, n);

	printmas(nums, n);
}