#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int mas[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
const int k = 4;

int compare(unsigned long i)
{
	if (mas[i] > k) return 1;
	else if (mas[i] < k) return -1;
	else return 0;
}

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
	unsigned long left = 0, right = nel - 1, mid = (left + right) / 2;
	while (left <= right)
	{
		int res = compare(mid);

		if (res == 1) right = mid - 1;
		else if (res == -1) left = mid + 1;
		else return mid;

		mid = (right + left) / 2;
	}

	return nel;
}

int main()
{
        printf("%lu\n", binsearch(SIZE, compare));
        return 0;
}