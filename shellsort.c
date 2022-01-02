#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *mas;

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
int fib1(int nel)
{
	int a = 0, b = 1, s = 0;

	while(a + b < nel)
	{
		s = a + b;
		a = b;
		b = s;
	}
	return s;
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

int insertSort(int mas[], int n)
{
	if (n == 1) return *mas;
	int i = 1, elem = 0, loc = 0;
	while (i < n)
	{
		elem = mas[i];
		loc = i-1;
		while (loc >= 0 && mas[loc] >= elem)
		{
			mas[loc+1] = mas[loc];
			loc--;
		}
		mas[loc+1] = elem;
		i++;
	}
	return *mas;
}

void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
	unsigned long d = fib(nel,1), loc = 0;
	while(d >= 1)
	{
		for(unsigned long i = d; i < nel; i++)
		{
			loc = i;
			while(loc >= d && compare(loc - d, loc) > 0)
			{
				swap(loc, loc - d);
				loc -= d;
			}
		}
		d = prev_fib(d);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	mas = (int*) malloc(n * sizeof(int));

	*mas = scanmas(mas,n);

	shellsort(n, compare, swap);

	printmas(mas, n);

	free(mas);
	return 0;
}