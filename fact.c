#include <stdio.h>
#include "bignums.h"

int main(void)
{
	char arr1[9] = "000000010", arr2[9] = "000000009", arr3[9] = "000000001";
	
	int i;
	for(i = 1; i<10; i++)
	{
		multbignums(arr1, arr2, 1);
		subbignums(arr2, arr3, 1);
	}

	int j;
	for(j = 0; j<9; j++) printf("%c", arr1[j]);
	printf("\n");
	getchar();

	return 0;
}