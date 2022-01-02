#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scanmas(int mas[], int n)
{
	for(long i = 0; i < n; i++)
		scanf("%d", &mas[i]);
	return *mas;
}

int isPower2(int x)
{
	if (x<=0) return 0;
	else return !(x & (x-1));
}

int count_pow2(int now, int mas[], int n, int it_sum)
{
    it_sum += mas[now];
    int check_pow = isPower2(it_sum);

    for (int j = now + 1; j < n; j++)
      check_pow += count_pow2(j, mas, n, it_sum);

    return check_pow;
}


int main()
{
    int n;
    scanf("%d", &n);

    int *nums = malloc(n * sizeof(int));
    *nums = scanmas(nums,n);

	  int ans = 0;
		for(long i = 0; i < n; i++)
			ans += count_pow2(i, nums, n, 0);

		printf("%d", ans);
    return 0;
}