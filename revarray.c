#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void revarray(char *base, unsigned long nel, unsigned long width)
{
	char *tmp = malloc(width);
	
	for(int i = 0; i < nel/2; i++)
	{
		char *left = base + i * width, *right = base + (nel - 1 - i) * width;
		
		memcpy(tmp, right, width);
		memcpy(right, left, width);
		memcpy(left, tmp, width);
	}
	
	free(tmp);
}



int main()
{
	/*char a[] = {1, 2, 3, 4, 5};
	int size = 5;
	revarray(a, size, sizeof(char));

	for (int i = 0; i < size; i++) 
		printf("%i ", a[i]);*/

return 0;
}