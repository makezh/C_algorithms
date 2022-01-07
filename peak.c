#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 6

int mas[] = { 4, 6, 7, 5, 9, 8 };

int less(unsigned long i, unsigned long j)
{
	if (mas[i] <= mas[j]) return 1;
	else return 0;
}

unsigned long peak(unsigned long nel,
        int (*less)(unsigned long i, unsigned long j))
{
	if (nel == 1) return 0;

	int count = 0;
	if(less(1,0)) return 0;
	else if (less(nel-2, nel-1)) return nel-1;

	for(unsigned long i = 1; i <= nel-2; i++)
		if(less(i-1,i) && less(i+1,i))
			return i;

	return 0;
}

int main()
{
	int i = peak(SIZE, less);
	printf("%d\n", i);
	return 0;
}