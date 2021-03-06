#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char *s, int pi[], int len)
{
    int t = 0;
    pi[0] = 0;
		int i = 1;
    while (i < len)
		{
      while(t > 0 && s[t] != s[i])
          t = pi[t-1];
  
      if (s[t] == s[i]) 
				t++;
      
			pi[i] = t;
			i++;
		}
}

void printmas(int mas[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", mas[i]);
		if (i == n-1) printf("\n");
	}
}
int kmpsubst(char *sub, char *s)
{
	int len = strlen(s), sublen = strlen(sub), pi[sublen], q = 0, k = 0;

	prefix(sub, pi, sublen);

	while (k < len)
	{
		while (q > 0 && sub[q] != s[k]) 
			q = pi[q-1];
		 
		if (sub[q] == s[k]) q++;
		
		if (q == 0) return 0;

		if (q == sublen) q = pi[q-1];


		k++;
	}
	return 1;
}


int main(int argc, char **argv)
{
	char *sub = argv[1], *word = argv[2];

	if(kmpsubst(sub, word)) 
		printf("yes\n");
  else 
		printf("no\n");

	return 0;
}