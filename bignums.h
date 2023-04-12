#include <math.h>

int * setbignums(int *arr1, int *arr2, int size)
{
	int i;
	for(i = 0; i<size; i++) arr1[i] = arr2[i];
	
	return arr1;
}

int compbignums(int *arr1, int *arr2, int size)
{
	int i;
	for(i = 0; i<size; i++)
	{
		if(arr1[i] > arr2[i])
		{
			return 1;
		} else if(arr1[i] < arr2[i])
		{
			return 2;
		}
	}
	
	return 0;
}

int * addbignums(int *arr1, int *arr2, int size)
{	
	int i;
	for(i = 0; i<size; i++) arr1[i] += arr2[i];
	
	int j;
	for(j = size-1; j>=0; j--) 
	{
		if(arr1[j] >= 1000000000)
		{
			arr1[j-1]++;
			arr1[j] -= 1000000000;
		}
	}
	
	return arr1;
}

int * subbignums(int *arr1, int *arr2, int size)
{	
	int i;
	for(i = 0; i<size; i++) arr1[i] -= arr2[i];
	
	int j;
	for(j = size-1; j>=0; j--) 
	{
		if(arr1[j] < 0)
		{
			arr1[j-1]--;
			arr1[j] += 1000000000;
		}
	}
	
	return arr1;
}

int * multbignums(int *arr1, int *arr2, int size)
{
	int temp[size], zero[size], one[size];
	int i;
	for(i = 0; i<size; i++) zero[i] = 0;
	
	setbignums(temp, arr1, size);
	setbignums(arr1, zero, size);
	setbignums(one, zero, size);
	one[size-1] = 1;
	
	while(compbignums(temp, zero, size) != 0)
	{
		addbignums(arr1, arr2, size);
		subbignums(temp, one, size);
	}
	
	int j;
	for(j = size-1; j>=0; j--) 
	{
		if(arr1[j] >= 1000000000)
		{
			arr1[j-1]++;
			arr1[j] -= 1000000000;
		}
	}
	
	return arr1;
}