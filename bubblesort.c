#include <stdio.h>
#include <stdlib.h>

int *mas;

int scanmas(int mas[], int n)
{
	for(int i = 0; i < n; i++)
		scanf("%d", &mas[i]);
	return *mas;
}

int compare(unsigned long i, unsigned long j)
{
	if (mas[i] < mas[j]) return -1;
	else if (mas[i] == mas[j]) return 0;
	else return 1;
}

void swap(unsigned long i, unsigned long j)
{
	int tmp = mas[i];
	mas[i] = mas[j];
	mas[j] = tmp;
}

void printmas(int mas[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", mas[i]);
		if (i == n-1) printf("\n");
	}
}

void bubblesort(unsigned long nel, 
        int (*compare)(unsigned long i, unsigned long j), 
        void (*swap)(unsigned long i, unsigned long j))
{ 
  int left = 0, right = nel - 1, new_left = left, new_right = right, noSwap=0;

  while(!noSwap)
  {
    noSwap = 1;
    for(int i = left; i < right; i++)
    {
      if(compare(i, i + 1) == 1)
      {
        swap(i, i + 1);
        noSwap = 0;
        new_right = i;
      }
    }
		right = new_right;

    if (noSwap == 1) 
			break;

    noSwap = 1;

    for(int i = right; i > left; i--)
    {
      if(compare(i - 1, i) == 1)
      {
        swap(i - 1, i);
        noSwap = 0;
				new_left = i;
      }
    }
    left = new_left;
  }
}

int main()
{
	int n;
	scanf("%d", &n);

	mas = (int*) malloc(n * sizeof(int));
	*mas = scanmas(mas,n);

	bubblesort(n, compare, swap);

	printmas(mas, n);

	free(mas);
	return 0;
}