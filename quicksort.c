#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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

void printmas(int mas[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", mas[i]);
		if (i == n-1) printf("\n");
	}
}

void SelectSort(int mas[], int left, int right)
{
	int j = right;
	while (j>left)
	{
		int k = j;
		int i = j-1;
		while (i >= left)
		{
			if (mas[k] < mas[i]) k = i;
			i--;
		}
		int tmp = mas[j];
		mas[j] = mas[k];
		mas[k] = tmp;
		j--;
	}
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

void QuickSortRec(int mas[], int left, int right, int m)
{
	if (right - left + 1 < m) SelectSort(mas, left, right);
	else
	{
		if (left < right)
		{
			int q = Partition(mas,left,right);
			QuickSortRec(mas,left, q-1,m);
			QuickSortRec(mas,q+1,right,m);
		}
	}
}

void QuickSort(int mas[], int n, int m)
{
	QuickSortRec(mas,0,n-1,m);
}


int main()
{
	int n,m;
	scanf("%d %d", &n, &m);

	int mas[n];

	*mas = scanmas(mas,n);

	QuickSort(mas,n,m);

	printmas(mas, n);

	return 0;
}