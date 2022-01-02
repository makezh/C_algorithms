#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_space(char c) {
    return c == ' ' || c == '\n' || c == '\0';
}

int is_not_space(char c) {
    return 0 == is_space(c);
}


int count_of(char* str, int (*pred)(char)) {
    int count = 0;
    
    while (*str != 0) {
        if (pred(*str)) {
            count++;
            str++;
        }
        else
            break;
    }
    return count;
}

int wcount(char* str) {
    int len = strlen(str);
    
    int count = 0;
    int i = 0;
    while (1) {
        int spaces_count = count_of(&str[i], is_space);
        i += spaces_count;
        if (i >= len) {
            break;
        }
            
        int word_length = count_of(&str[i], is_not_space);
        if (word_length > 0) {
            count++;
        }
            
        i += word_length;
        if (i >= len) {
            break;
        }
    }
    return count;
}


void csort(char *src, char *dest) 
{
	char **words;
	int wc = wcount(src), null_term_idx = 0;

	int count[wc];
	for(int i = 0; i < wc; i++) count[i] = 0;

	for(int i = 0; i < wc - 1; i++)
	{
		int l1 = strlen(words[i]);
		null_term_idx += l1 + 1;

		for(int j = i + 1; j < wc; j++)
		{
			int l2 = strlen(words[j]);

			if(l1 > l2) count[i] += l2 + 1;
			else count[j] += l1 + 1;
		}
	}

	null_term_idx += strlen(words[wc-1]);

	for(int i = 0; i < wc; i++)
		strcpy(dest + count[i], words[i]);

	for(int i = 0; i < wc; i++)
		if(count[i] != 0) dest[count[i] - 1] = ' ';

	dest[null_term_idx] = '\0';

	for(int i = 0; i < wc; i++)
		free(words[i]);
	free(words);
}

int get_string(char **p)
{
	char *words = (char*)malloc(sizeof(char)), c;
	scanf("%c", &c);

	int slen = 0;
	while(c != '\n')
	{
		words[slen] = c;
		words = (char*)realloc(words, sizeof(char) * (slen * 2));
		scanf("%c", &c);
	}
	words[slen] = '\0';

	*p = words;
	return slen;
}

int main()
{
	char *string;
	int slen = get_string(&string);

	char sorted_string[slen];
	csort(string, sorted_string);

	printf("%s\n", sorted_string);
	free(string);
	return 0;
}