#include <stdio.h>

long long Gorner(long long n, long long p[], long long x0)
{
	long long result = p[0];
	int i = 0;
	while (i < n-1)
	{
		result *= x0;
		result += p[i+1];
		i++;
	}
	return result;
}

int main(int argc, char **argv) {
	long long x0, n;
	scanf("%lld %lld", &n, &x0);
	long long k[n+1]; // коэффиценты функции
	for(int i = 0; i <= n; i++)
		scanf("%lld", &k[i]);
		
	long long res = Gorner(n+1, k, x0); // значение в точке x0

	long long deriv[n]; // коэффиценты производной
	int i = 0;
	while (i < n)
	{
		deriv[i] = k[i]*(n-i);
		i++;
	}
	
	long long resd = Gorner(n, deriv, x0); // значение производной в точке x0

	printf("%lld ", res); 
	printf("%lld\n", resd); 
	
  return 0;
}