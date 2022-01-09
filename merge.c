#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN -2147483648;

#define printmas()

struct Priority{
    int values;
    int keys;
};

struct PriorityQueue{
    struct Priority *heap;
    int cap;
    int count;
};

void InitPriorityQueue(struct PriorityQueue *q, int n)
{
	(*q).heap = (struct Priority *)malloc(sizeof(struct Priority) * n);
  (*q).cap = n;
  (*q).count = 0;
}


int Heapify(struct Priority *mas, int size) {
    int cap = 0;
		int i = cap;

    while (i < size/2)
    {
        int left = 2*i + 1, right = 2*i+ 2, j = left;

        if(right < size && mas[left].keys < mas[right].keys) 
        	j = right;

        if(mas[i].keys >= mas[j].keys)
        	return cap;

				struct Priority tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;

				cap = j;
        i = cap;
    }
    return cap;
}

struct Priority Pop(struct PriorityQueue *q)
{
    struct Priority x = (*q).heap[0];

    (*q).heap[0].keys = MIN;

    (*q).count = Heapify((*q).heap, (*q).cap);

    return x;
}

void Insert(struct PriorityQueue *q, struct Priority ptr)
{
    int i = (*q).count;

		if (i == (*q).cap) printf("Переполение");
		else
		{
			(*q).count++;
			(*q).heap[i] = ptr;
			while (i > 0 && (*q).heap[i].keys > (*q).heap[(i - 1) / 2].keys)
			{
				struct Priority tmp = (*q).heap[i];
				(*q).heap[i] = (*q).heap[(i-1)/2];
				(*q).heap[(i - 1) / 2] = tmp;
				i--;
				i /= 2;
			}
		}
}

int main() {
  int n;
	int SIZE = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++)
  {
      int k;
      scanf("%d", &k);
      SIZE += k;
  }
  struct PriorityQueue queue;
  InitPriorityQueue(&queue, SIZE);

  for(int i = 0; i < SIZE; i++)
  {
      int x;
			struct Priority seq;

      scanf("%d", &x);

      seq.values = x;
      seq.keys = -seq.values;

      Insert(&queue, seq);
  }


  for(int i = 0; i < SIZE; i++)
	{
		if (i == SIZE - 1) printf("%d\n", Pop(&queue).values);
		else printf("%d ", Pop(&queue).values);
	}
  free(queue.heap);
}