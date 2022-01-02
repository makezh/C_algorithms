#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *mas;

int abs(int x)
{
	if (x < 0) return -x;
	else return x;
}

unsigned long fib(unsigned long long n, int type)// 0 - index; 1 - number
{
	if (n == 0 || n == 1)
	{
	if (type == 1) return n;
	else return 1;
	}

	unsigned long long f1 = 0, f2 = 1, f3 = 1, i = 0;
	while (f3 < n)
	{
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
		i+=1;
		//printf("%lld ", i);
	}
	if (type == 1)
		return f2;
	else 
		return i;
}




int prev_fib(int fib)
{
	if(fib == 1) return 0;
	double PHI = (1+sqrt(5))/2;
	
	double prev_fib = fib/PHI; 
	return (int)round(prev_fib);
}

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

void insertSort(int mas[], int left, int right)
{
	int i = left+1, elem = 0, loc = 0;
	while (i <= right)
	{
		elem = mas[i];
		loc = i-1;
		while (loc >= left && abs(mas[loc]) >= abs(elem))
		{
			mas[loc+1] = mas[loc];
			loc--;
		}
		mas[loc+1] = elem;
		i++;
	}

}

void Merge(int mas[], int left, int med, int right)
{
	int sortMas[right - left + 1], i = left, j = med + 1, h = 0;
	while (h < right - left + 1)
	{
		if (j <= right && (i == med + 1 || (abs(mas[j]) < abs(mas[i]))))
		{
			sortMas[h] = mas[j];
			j++;
		}
		else
		{
			sortMas[h] = mas[i];
			i++;
		}
		h++;
	}
	for(int i = left; i <= right; i++)
		mas[i] = sortMas[i];
}

void MergeSortRec(int mas[], int left, int right)
{
	if (right - left + 1 < 5) insertSort(mas,left,right);
	else
	{
		int med = floor((right + left)/2);
		MergeSortRec(mas,left,med);
		MergeSortRec(mas,med+1,right);
		Merge(mas, left, med, right);
	}
}

void MergeSort(int mas[], int n)
{
	MergeSortRec(mas, 0, n-1);
}



int main()
{
	int n;
	scanf("%d", &n);

	mas = (int*) malloc(n * sizeof(int));

	*mas = scanmas(mas,n);

	MergeSort(mas,n);

	printmas(mas, n);

	free(mas);
	return 0;
}