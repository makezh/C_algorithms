#include <stdio.h>
unsigned long long fib(unsigned long long n, int type)// 0 - index; 1 - number
{
	if (n == 0 || n == 1)
	{
	if (type == 1)
		return n;
	else 
		return 1;
	}

	unsigned long long f1 = 0, f2 = 1, f3 = 1, i = 0;
	while (f3 <= n)
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

void fibsys(long long n, long long ans[])
{
	while (n > 0)
	{
		long long f = fib(n, 1);
		ans[fib(n,0)-1] = 1;
		//printf("%lld ", f);
		n = n - f;
	}
}

int reverse(int value){
    int tmp = 0;
    while(value > 0){
        tmp = 10 * tmp + value % 10;
        value /= 10;
    }
    return tmp;
}

int main()
{
	long long n;
	scanf("%lld", &n);
	//printf("\n%lld %lld\n", fib(n,0),fib(n,1));
	long long LEN = fib(n,0);
	long long ans[LEN];
	for(int i=0; i< LEN; i++)
		ans[i] = 0;
	
	//printf("%lld", fib(n,1));
	fibsys(n,ans);
	for(int i=LEN; i>0;i--)
	printf("%lld", ans[i-1]);

	//for(int i=0; i< LEN; i++)
	//printf("%lld", ans[i]); 
	return 0;
}

