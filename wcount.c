#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

int main() {
    char str[1000];
    
		fgets(str, sizeof(str), stdin);
    
    printf("%d", wcount(str));
    
    return 0;
}  