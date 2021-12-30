#include <stdio.h>
#include <math.h>
//алгоритм "решето Эратосфена"
int reverse(int value){
    int tmp = 0;
    while(value > 0){
        tmp = 10 * tmp + value % 10;
        value /= 10;
    }
    return tmp;
}

void Neg(long long *n)
{
	if (*n < 0) *n *=-1;
}

long long sum(long long a, long long b)
{
	return a+b;
}

long long mult(long long a, long long b)
{
	return a*b;
}

void order(long long mas[], long long n)
{
	for(int i=0; i<n; i++)
	mas[i] = i;
}

long long answer(long long mas[], long long n)
{
	long long ans = 1;
	for(int i=0; i<n; i++){
		if(mas[i]!=0 && n%mas[i]==0)
		{
			ans = mas[i];
		}
	}
	return ans;
}

void sieve(long long mas[], long long n)
{
	mas[1] = 0;
	for(int i=2; i<n; i++){
		if(mas[i]!=0){
			for(int j=i*2; j<n; j+=i)
			{
				mas[j]=0;
			}
		}
	}
}

long long maxPrimeFactors(long long n)
{
    long long maxPrime = -1;
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2; 
    }

    while (n % 3 == 0) {
        maxPrime = 3;
        n /= 3;
    }

    for (int i = 5; i <= sqrt(n); i += 6) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
        while (n % (i + 2) == 0) {
            maxPrime = i + 2;
            n = n / (i + 2);
        }
    }

    if (n > 4)
        maxPrime = n;
 
    return maxPrime;
}
 
// Driver program to test above function
int main()
{
	long long N;
	scanf("%lld", &N);
	Neg(&N);

	long long a[N%5];
	order(a,N%5);
	sieve(a,N%5);
	//printf("%d", (-4)%5);
	printf("%lld", maxPrimeFactors(N));
 
    return 0;
}