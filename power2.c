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

int smalleroreqThan(int x, int y)
{
	return x <= y;
}

int isPower2(int x)
{
	if (smalleroreqThan(x,0)) return 0;
	else return !(x & (x-1));
}

int incPow2(int *ans, int x)
{
	int answer = 0;
	if (isPower2(x)) answer = inc(&*ans);
		return answer;
}

void count_pow2(int *ans, int *mas, int now, int n, int sum)
{
	if (smallerThan(now, n))
	{
		if (isPower2(sum)) (*ans)++;
  	for (int i = now+1; i < n; i++)
  		count_pow2(ans, mas, i, n, sum + mas[i]);
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
		for(int i = 0; i < n; i++)
			count_pow2(&ans, nums, i, n, nums[i]);


		printf("%d", ans);
		free(nums);
    return 0;
}