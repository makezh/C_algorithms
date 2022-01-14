#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 26

void key(char* str, int count[])
{
	int n = strlen(str);
	for(int i = 0; i < n; i++)
		count[str[i]-'a']++;
}

void dsort(char* str) {
		int count[26] = {0};

		key(str,count);

		for (int i = 0; i < MAX_CHAR; i++)
			for(int j = 0; j < count[i]; j++)
				printf("%c", (char)(i+'a'));

}

int main() {
		char* str=NULL;
		if(scanf("%m[^\n]", &str))
		{
			dsort(str);
			free(str);
		}

		else printf("\n");
		return 0;
}