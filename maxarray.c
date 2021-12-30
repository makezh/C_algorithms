#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(char *a, char *b)
{
	if ((int)(*(unsigned char*)a) > (int)(*(unsigned char*)b))
		return 1;
	else if ((int)(*(unsigned char*)a) < (int)(*(unsigned char*)b))
					return -1;
			else return 0;
}

int maxarray(char *base, size_t nel, size_t width,
        int (*compare)(char *a, char *b))
{
	char *max = malloc(width);
	int maxind = 0;
	
	memcpy(max, base, width);

	for (int i = 1; i < nel; i++)
	{
		if (compare(base + i*width, max) > 0) 
		{
			memcpy(max, base + i*width, width);
			maxind = i;
		}
	}

	free(max);
	return maxind;
}

int main()
{
	/*unsigned char a[] = {1, 2, 5 ,4, 3 ,1};
	int n = 6;
	printf("%d\n", maxarray(a, n, sizeof(unsigned char), compare));*/
	return 0;
}