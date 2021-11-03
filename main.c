#include <stdio.h>

long long Gorner(long long n, long long p[], long long x0)
{
	long long result = p[0];
	for(int i = 0; i < n-1; i++)
	{
		result *= x0;
		result += p[i+1];
	}
	return result;
}

int main(int argc, char **argv) {
	long long x0, n;
	scanf("%lld %lld", &n, &x0);
	long long p[n]; // коэффиценты функции
	for(int i = 0; i < n; i++)
		scanf("%lld", &p[i]);
		
	long long res = Gorner(n, p, x0); // значение в точке x0
		printf("%lld\n", res);

	long long deriv[n-1]; // коэффиценты производной
	for(int i = 0;i < n-1; i++)
		deriv[i] = p[i]*(n-1-i);
	
	long long resp = Gorner(n-1, deriv, x0); // значение производной в точке x0
	printf("%lld\n", resp); 
  return 0;
}