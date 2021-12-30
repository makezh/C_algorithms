#include <stdio.h>
#define SIZE 32
long long scanSet(long long powSet)
{
	long long Set = 0, tmp = 0, pos = 0;
    for (int i = 0; i < powSet; i++){
        scanf("%lld", &pos);
        tmp = 1 << pos;
       Set |= tmp;
    }
		return Set;
}

void answer(long long set1, long long set2)
{
	long long ans = set1 & set2, tmp = 0;
	for(int i=0;i<SIZE; i++)
	{
		tmp = 1 << i;
		if ((tmp & ans) != 0)
		{
			printf("%d ", i);
		}
	}
}

int main() {
	long long X = 0, powX = 0, Y = 0, powY = 0, ans = 0;
	
    scanf("%lld ", &powX);
    X = scanSet(powX);

    scanf("%lld ", &powY);
    Y = scanSet(powY);

		answer(X,Y);

    return 0;
}
