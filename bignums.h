#include <math.h>

void strtonum(char *str, int *arr, int size)
{
	int i, k;
	for(i = 1; i<=size; i++)
	{
		for(k = 8; k>=0; k--) arr[i-1] += (str[(9*i-k)-1]-48)*pow((double)10, (double)k);
	}
}

void numtostr(int *arr, char *str, int size)
{
	int i, k;
	for(i = 1; i<=size; i++)
	{
		for(k = 8; k>=0; k--)
		{
			str[(9*i-k)-1] = ((int)floor(arr[i-1] / pow((double)10, (double)k)) % 10)+48;
		}
	}
}

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

char * addbignums(char *str1, char *str2, int size)
{	
	int arr1[size], arr2[size];

	int l;
	for(l = 0; l<size; l++)
	{
		arr1[l] = 0;
		arr2[l] = 0;
	}

	strtonum(str1, arr1, size);
	strtonum(str2, arr2, size);

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
	numtostr(arr1, str1, size);
	
	return str1;
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
/*
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
	
	return arr1;
}*/

int * divbignums(int *arr1, int *arr2, int size)
{
	
	
	return arr1;
}