#include <stdio.h>

void readMas(long long mas[], long long n)
{
	for (int i =0; i < n; i++)
		scanf("%lld", &mas[i]);
}

void sumMas(long long mas[],long long n, long long *sum)
{
	for(int i=0;i<n;i++)
		*sum += mas[i];
}

void findK(long long mas[], long long k, long long n, long long *sum, long long *maxsum)
{
	for(int i = k; i < n; i++)
	{
		//printf("sum: %lld  1st: %lld   2nd: %lld  ", *sum, mas[i%k], mas[i]);
		*sum -= mas[i % k];
		*sum += mas[i];
		//printf("sum2: %lld\n", *sum);
		if(*sum > *maxsum)
		{
			*maxsum = *sum;
		}
		mas[i%k] = mas[i];
	}	
} 

void writemas(long long mas[], long long n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%lld ", mas[i]);
	}
}

int main()
{
	long long n, k, sum = 0, maxsum = 0;
	scanf("%lld", &n);
	long long a[n];

	readMas(a, n);
	scanf("%lld", &k);

	sumMas(a,k, &sum);

	maxsum = sum;

	findK(a, k, n, &sum, &maxsum);

	printf("%lld", maxsum);
	return 0;
}