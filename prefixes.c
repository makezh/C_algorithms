#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char *s)
{
    int t = 0, len = strlen(s), pi[len];
    pi[0] = 0;
		int i = 1;
    while (i < len)
		{
      while(t > 0 && s[t] != s[i])
          t = pi[t-1];
  
      if (s[t] == s[i]) 
				t++;
      
			pi[i] = t;

      int count = i + 1;
      if(pi[i] > 0 && (count % (count - pi[i])) == 0)
        printf("%d %d\n", count, (int)(count / (count - pi[i])));
			i++;
		}
}

int main(int argc, char **argv)
{
    char *str = argv[1];
    
    prefix(str);

    return 0;
}