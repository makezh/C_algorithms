#include <stdio.h>

int main(int argc, char **argv){
	long long a[8], b[8], sum1=0,sum2=0,mp1=1,mp2=1;
	for (int i =0;i<8;i++)
	{
		scanf("%lld", &a[i]);
		sum1 += a[i];
		mp1 *= a[i];
	}
	for (int i =0;i<8;i++)
	{
		scanf("%lld", &b[i]);
		sum2 += b[i];
		mp2 *= b[i];
	}
	if ((sum1 == sum2) && (mp1 == mp2))
		printf("yes");
	else printf("no");
	return 0;
}