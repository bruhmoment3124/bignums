#include <math.h>

void setbignums(int *arr1, int *arr2, int size)
{
	int i;
	for(i = 0; i<size; i++)
	{
		arr1[i] = 0;
		arr1[i] = arr2[i];
	}
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
	int times = 0;
	
	int i;
	for(i = size; i>0; i--) times += (((int)pow(10, ((i-size))*-1)))*arr2[i-1];
		
	int temp[size];
	int k;
	for(k = 0; k<size; k++)
	{
		temp[k] = arr1[k];
		arr1[k] = 0;
	}
	
	int j;
	for(j = 0; j<times; j++) addbignums(arr1, temp, size);
}