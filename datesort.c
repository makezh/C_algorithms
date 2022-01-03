#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int INDEX;

int addElem(int mas[], int n, int elem)
{
	for(int i = 0; i < n; i++)
		mas[i] = elem;
	return *mas;
}


struct Date
{
	int Year, Month, Day;
};




int key(struct Date date)
{
	int keys[] = {date.Day - 1, date.Month - 1, date.Year - 1970};
	return keys[INDEX];
}


void datesort(int base, struct Date *dates, int n)
{
	int* count = (int*)malloc(sizeof(int)*base);

	*count = addElem(count, base, 0);
	
	for(int i = 0; i < n; i++)
	{
		int k = key(dates[i]);
		//printf("%d\n", k);
		count[k]++;
	}

	for(int i = 1; i < base; i++)
		count[i] += count[i - 1];

	struct Date sortDate[n];

	for(int i = n - 1; i >= 0; i--)
	{
		int k = key(dates[i]);
		count[k]--;
		int j = count[k];
		sortDate[j] = dates[i];
	}

	for(int i = 0; i < n; i++) 
		dates[i] = sortDate[i];

	free(count);
}


int main()
{
	int n;
	int basis[] = {31, 12, 61};
	scanf("%i", &n);
	struct Date dates[n];
	for(int i = 0; i < n; i++) 
		scanf("%d %d %d", &(dates+i)->Year, &(dates+i)->Month, &(dates+i)->Day);

	for(int i = 0; i < 3; i++)
	{
		INDEX = i;
		datesort(basis[i], dates, n);
	}

	for(int i = 0; i < n; i++)
	{
		printf("%04d %02d %02d\n", (dates+i)->Year, (dates+i)->Month, (dates+i)->Day);
	}
	return 0;
}