#include <stdio.h>
#include "bignums.h"

int main(void)
{
	char arr1[901], arr2[901], arr3[901];
	
	int k;
	for(k = 0; k<901; k++)
	{
		arr1[k] = '0';
		arr2[k] = '0';
		arr3[k] = '0';
	}
	arr1[100*9-10] = '.';
	arr1[100*9-13] = '1';
	
	
	arr2[100*9-10] = '.';
	arr2[100*9-11] = '9';
	arr2[100*9-12] = '9';
	
	
	arr3[100*9-10] = '.';
	arr3[100*9-11] = '1';
	
	int i;
	for(i = 1; i<100; i++)
	{
		multbignums(arr1, arr2, 99, 100);
		subbignums(arr2, arr3, 99, 100);
	}

	int j;
	for(j = 0; j<901; j++) printf("%c", arr1[j]);
	printf("\n");
	getchar();

	return 0;
}