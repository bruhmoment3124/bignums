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
	
	int k;
	for(k = size-1; k>=0; k--) 
	{
		if(arr1[k] >= 10)
		{
			arr1[k-1]++;
			arr1[k] -= 10;
		}
	}
}

void subbignums(int *arr1, int *arr2, int size)
{	
	int i;
	for(i = 0; i<size; i++) arr1[i] -= arr2[i];
	
	int k;
	for(k = size-1; k>=0; k--) 
	{
		if(arr1[k] < 0)
		{
			arr1[k-1]--;
			arr1[k] += 10;
		}
	}
}

void multbignums(int *arr1, int *arr2, int size)
{
	int temp1[size];
	int a;
	for(a = 0; a<size; a++) temp1[a] = 0;
	
	int i;
	for(i = size-1; i>=0; i--)
	{
		int temp2[size];
		int j;
		for(j = 0; j<size; j++) temp2[j] = 0;
		
		int k;
		for(k = 0; k<arr2[i]; k++) addbignums(temp2, arr1, size);
		
		int l, length = 0;
		for(l = 0; l<size; l++)
		{
			if(temp2[l] != 0) 
			{
				length = size - l;
				break;
			}
		}
		
		int m;
		for(m = 0; m<length; m++) temp1[i-m] += temp2[size-1-m];
	
		if(temp1[i] >= 10)
		{
			temp1[i-1]++;
			temp1[i] -= 10;
		}
		
		if(temp1[i] >= 10)
		{
			temp1[i-1]++;
			temp1[i] -= 10;
		}
	}
	setbignums(arr1, temp1, size);
}