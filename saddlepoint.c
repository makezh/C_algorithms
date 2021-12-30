#include <stdio.h>
#include <stdlib.h>
#define inf 1e5;

long long answery(long long mas[], long long n)
{
	long long ans = 1;
	for(int i=0; i<n; i++){
		if(mas[i]!=0 && n%mas[i]==0)
		{
			ans = mas[i];
		}
	}
	return ans;
}

void sieve(long long mas[], long long n)
{
	mas[1] = 0;
	for(int i=2; i<n; i++){
		if(mas[i]!=0){
			for(int j=i*2; j<n; j+=i)
			{
				mas[j]=0;
			}
		}
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

void Neg(long long *n)
{
	if (*n < 0) *n *=-1;
}

long long sum(long long a, long long b)
{
	return a+b;
}

long long mult(long long a, long long b)
{
	return a*b;
}

void order(long long mas[], long long n)
{
	for(int i=0; i<n; i++)
	mas[i] = i;
}

void mincolumn(long long mas[], long long m)
{
	for (int i = 0; i < m; i++) mas[i] = inf;
}

void maxrow(long long mas[], long long n)
{
	for (int i = 0; i < n; i++) mas[i] = -inf;
}


void run(long long n, long long m,long long mas[][m], long long col[],long long colk[],long long row[],long long rowk[])
{
	for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%lld", &mas[i][j]);
            if (mas[i][j] < col[j]){
                col[j] = mas[i][j];
               	colk[j] = j;
            }
            if (mas[i][j] > row[i]){
                row[i] = mas[i][j];
                rowk[i] = i;
            }
        }
}
}

void answer(long long n, long long m,long long mas[][m], long long col[],long long colk[],long long row[],long long rowk[])
{
	for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (row[i] == col[j]){
                printf("%lld %lld", rowk[i], colk[j]);
								exit(1);
            }
        }
    }
}

int main(){
    long long n, m, s[10][10], rowmax[10], colmin[10], rowkord[10], colkord[10];
    scanf("%lld %lld", &n, &m);

		long long a=5,b=2;
		long long SUMMMM = sum(a,b);
		long long MULTIIII = mult(a,b);
		Neg(&a);

    mincolumn(colmin,m);
		maxrow(rowmax,n);

		run(n,m,s,colmin,colkord,rowmax,rowkord);
		
		answer(n,m,s,colmin,colkord,rowmax,rowkord);

    printf("none");
    return 0;
}

/*
3 4
10 11 7 13
1 2 5 3
14 15 8 16
-> 1 2
*/