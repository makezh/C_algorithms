#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scanmas(int mas[], int n)
{
	for(long i = 0; i < n; i++)
		scanf("%d", &mas[i]);
	return *mas;
}

int inc(int *i)
{
	return (*i)+1;
}

int smallerThan(int x, int y)
{
	return x < y;
}
int isPower2(int x)
{
	if (x<=0) return 0;
	else return !(x & (x-1));
}

int incPow2(int *ans, int x)
{
	int answer = 0;
	if (isPower2(x)) answer = inc(&*ans);
		return answer;
}

void count_pow2(int *ans, int mas[], int now, int n, int sum)
{
	if (smallerThan(now, n))
	{
		if (isPower2(sum)) (*ans)++;
  	for (int i = now; i < n; i++)
  		count_pow2(ans, mas, inc(&now), n, sum + mas[now]);
	}
}


int main()
{
    int n;
    scanf("%d", &n);

    int *nums = malloc(n * sizeof(int));
    *nums = scanmas(nums,n);
		int answer = incPow2(&answer,4);

	  int ans = 0;
		count_pow2(&ans, nums, 0, n, 0);


		printf("%d", ans);
    return 0;
}