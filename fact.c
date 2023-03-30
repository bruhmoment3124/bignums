#include <stdio.h>
#include "bignums.h"

int main(void)
{
	int arr1[2600] = {0}, arr2[2600] = {0}, arr3[2600] = {0};
	
	arr1[2596] = 1;
	arr1[2597] = 0;
	arr1[2598] = 0;
	arr1[2599] = 0;
	
	arr2[2596] = 0;
	arr2[2597] = 9;
	arr2[2598] = 9;
	arr2[2599] = 9;
	
	arr3[2599] = 1;
	
	int i;
	for(i = 1; i<=999; i++)
	{
		multbignums(arr1, arr2, 2600);
		subbignums(arr2, arr3, 2600);
	}

	int j;
	for(j = 0; j<2600; j++) printf("%d", arr1[j]);
	printf("\n");

	getchar();

	return 0;
}