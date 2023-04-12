#include <stdio.h>
#include "bignums.h"

int main(void)
{
	int arr1[1] = {0}, arr2[1] = {0}, arr3[1] = {0};
	
	arr1[0] = 10;
	arr2[0] = 9;
	arr3[0] = 1;
	
	int i;
	for(i = 1; i<10; i++)
	{
		multbignums(arr1, arr2, 1);
		subbignums(arr2, arr3, 1);
	}

	int j;
	for(j = 0; j<1; j++) printf("%09d", arr1[j]);
	printf("\n");
	getchar();

	return 0;
}