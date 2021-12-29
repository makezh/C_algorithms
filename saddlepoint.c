#include <stdio.h>

#define inf 1e5;

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

int main(){
    long long n, m, s[10][10], rowmax[10], colmin[10], rowkord[10], colkord[10];
    scanf("%lld %lld", &n, &m);

    mincolumn(colmin,m);
		maxrow(rowmax,n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%lld", &s[i][j]);
            if (s[i][j] < colmin[j]){
                colmin[j] = s[i][j];
               	colkord[j] = j;
            }
            if (s[i][j] > rowmax[i]){
                rowmax[i] = s[i][j];
                rowkord[i] = i;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (rowmax[i] == colmin[j]){
                printf("%lld %lld", rowkord[i], colkord[j]);
                return 0;
            }
        }
    }
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