#include <math.h>

void setbignums(int *arr1, int *arr2, int size)
{
	int i;
	for(i = 0; i<size; i++) arr1[i] = arr2[i];
}

void addbignums(int *arr1, int *arr2, int size)
{	
	int i;
	for(i = 0; i<size; i++) arr1[i] += arr2[i];
	
	int j;
	for(j = size-1; j>=0; j--) 
	{
		if(arr1[j] >= 10)
		{
			arr1[j-1]++;
			arr1[j] -= 10;
		}
	}
}

void subbignums(int *arr1, int *arr2, int size)
{	
	int i;
	for(i = 0; i<size; i++) arr1[i] -= arr2[i];
	
	int j;
	for(j = size-1; j>=0; j--) 
	{
		if(arr1[j] < 0)
		{
			arr1[j-1]--;
			arr1[j] += 10;
		}
	}
}

void multbignums(int *arr1, int *arr2, int size)
{
	int temp1[size];
	int i;
	for(i = 0; i<size; i++) temp1[i] = 0;
	
	int j;
	for(j = size-1; j>=0; j--)
	{
		int temp2[size];
		int k;
		for(k = 0; k<size; k++) temp2[k] = 0;
		
		int l;
		for(l = 0; l<arr2[j]; l++) addbignums(temp2, arr1, size);
		
		int m, length = 0;
		for(m = 0; m<size; m++)
		{
			if(temp2[m] != 0) 
			{
				length = size - m;
				break;
			}
		}
		
		int n;
		for(n = 0; n<length; n++) temp1[j-n] += temp2[size-1-n];
	
		while(temp1[j] >= 10)
		{
			temp1[j-1]++;
			temp1[j] -= 10;
		}
	}
	setbignums(arr1, temp1, size);
}