#include <stdio.h>
#include "bignums.h"

int main(void)
{
	char arr1[19] = "000000007.000000000", arr2[19] = "000000006.000000000", arr3[19] = "000000001.000000000";
	
	int i;
	for(i = 1; i<7; i++)
	{
		multbignums(arr1, arr2, 1, 2);
		subbignums(arr2, arr3, 1, 2);
	}

	int j;
	for(j = 0; j<19; j++) printf("%c", arr1[j]);
	printf("\n");
	getchar();

	return 0;
}