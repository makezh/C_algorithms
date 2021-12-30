#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 6

int mas[] = { 5, 5, 5, 5, 6, 4 };

int less(unsigned long i, unsigned long j)
{
	if (mas[i] < mas[j]) return 1;
	else return 0;
}

unsigned long peak(unsigned long nel,
        int (*less)(unsigned long i, unsigned long j))
{
	unsigned long left = 0, right = nel - 1, mid=(left + right) / 2;
	while(left <= right)
	{
    if (less(mid, mid + 1)) 
		{
      left = mid + 1;
    } 
		else if (less(mid, mid - 1)) 
				{
        	right = mid - 1;
    		}
		else return mid;
  }
    return left;
}

int main()
{
	int i = peak(SIZE, less);
	printf("%d\n", i);
	return 0;
}