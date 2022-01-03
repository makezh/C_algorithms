#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dsort(char* str) {
    int count[26] = {0};
    char* k = str;

    while (*k != '\0') 
		{
      count[*k - 'a']++;
      k++;
    }

    for (int i = 0; i < 26; i++)		
		{
      while (count[i]) 
			{
        *str = (char)i + 'a';
				count[i]--;
        str++;
      }
    }
}

int main() {
    char* str=NULL;
		if(scanf("%m[^\n]", &str) == 1)
		{
			dsort(str);
			printf("%s\n", str);
			free(str);
		}
		else printf("\n");
    return 0;
}