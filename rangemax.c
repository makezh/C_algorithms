#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scanmas(int mas[], int n)
{
	for(int i = 0; i < n; i++)
		scanf("%d", &mas[i]);
	return *mas;
}

int max(int a, int b)
{
	if (a>b) return a;
	else return b;
}

int query(int T[], int l, int r, int a, int b, int i)
{
	int left = 2*i + 1, right = 2*i + 2;
	if(l == a && r == b)
		return T[i];
	else
	{
		int m = (a + b) / 2;
		if(r <= m)
			return query(T, l, r, a, m, left);
		else 
			if(l > m)
				return query(T, l, r, m + 1, b, right);
			else
				return max(query(T, l, m, a, m, left), query(T, m + 1, r, m + 1, b, right));
	}
}

int SegmentTree_Query(int T[], int n, int l, int r)
{ 
	return query(T, l, r, 0, n - 1, 0);
}

void build(int v[], int a, int b, int T[], int i)
{
	int left = 2*i + 1, right = 2*i + 2;
	if(a == b)
		T[i] = v[a];
	else
	{
		int m = (a + b) / 2;
		build(v, a, m, T, left);
		build(v, m + 1, b, T, right);
		T[i] = max(T[left], T[right]);
	}
}

void SegmentTree_Build(int v[], int n, int **pT)
{
	int *T = (int *)malloc(sizeof(int) * 4*n);
	build(v, 0, n - 1, T, 0);
	*pT = T;
}

void update(int I, int v, int a, int b, int T[], int i)
{
	int left = 2*i + 1, right = 2*i + 2;
	if(a == b) 
		T[i] = v;
	else
	{
		int m = (a + b) / 2;
		if(I <= m)
			update(I, v, a, m, T, left);
		else
			update(I, v, m + 1, b, T, right);
		
		T[i] = max(T[left], T[right]);
	}
}

void SegmentTree_Update(int I, int v, int n, int T[])
{
	update(I, v, 0, n - 1, T, 0);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int nums[n];
	scanmas(nums, n);

	int *T=NULL;
	SegmentTree_Build(nums, n, &T);

	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		char action[3]; int l, r;
		scanf("%s %d %d", action, &l, &r);

		if(!strcmp(action,"UPD"))
			SegmentTree_Update(l, r, n, T);
		else
			if (!strcmp(action,"MAX"))
				printf("%i\n", SegmentTree_Query(T, n, l, r));
	}

	free(T);
	return 0;
}