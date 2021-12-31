#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void scanmas(long mas[], long n)
{
	for(long i = 0; i < n; i++)
		scanf("%ld", &mas[i]);
}

int power2(int x)
{
	if (x<=0) return 0;
	else return !(x & (x-1));
}

long sum_pow2(long now, long mas[], long n, long it_sum)
{
    it_sum += mas[now];
    long check_pow = power2(it_sum);

    for (long j = now + 1; j < n; j++)
      check_pow += sum_pow2(j, mas, n, it_sum);

    return check_pow;
}


int main()
{
    long n;
    scanf("%ld", &n);

    long *nums = malloc(n * sizeof(long));
    scanmas(nums,n);
		
		long ans = 0;
		for(long i = 0; i < n; i++)
			ans += sum_pow2(i, nums, n, 0);

		printf("%ld", ans);
    return 0;
}