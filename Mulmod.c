#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
	long long a, b, m, b2[1000];
	scanf("%lld %lld %lld", &a, &b, &m);
	long long x = b,i=0,res=0;
	while (x) // двоичное представление b (b0, b1, b2...)
	{
		b2[i] = x%2;
		x /= 2;
		i++;
	}
	res = a*b2[--i];

	for(int j = i-1; j>0;j--) // используем схему Горнера 
	{
		res *=2;
		res += a*b2[j-1];
	}
	res %= m;
	printf("%lld\n", res);
	/*for(int i = 0; i < 10; i++)
	{
		printf("%lld ", b2[i]);
	}*/
	return 0;
}