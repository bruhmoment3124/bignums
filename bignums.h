#include <math.h>

void strtonum(char *str, int *arr, int size)
{
	char temp[size*9];
	
	int j, f = 0;
	for(j = 0; j<size*9; j++)
	{
		temp[j] = '0';
		
		if(str[j] == '.') f++;
		temp[j] = str[j+f];
	}

	int i, k;
	for(i = 1; i<=size; i++)
	{
		for(k = 8; k>=0; k--)
		{	
			arr[i-1] += (temp[(9*i-k)-1]-48)*pow((double)10, (double)k);
		}
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

int sizeofstr(char *str)
{
	int n = 0;
	
	int i;
	for(i = 0; str[i] != '\0'; i++) n++;

	return n;
}

char * setbignums(char *str1, char *str2, int size)
{
	int i;
	for(i = 0; i<size*9; i++) str1[i] = str2[i];
	
	return str1;
}

int compbignums(char *str1, char *str2, int size)
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

char * subbignums(char *str1, char *str2, int size)
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
	numtostr(arr1, str1, size);
	
	return str1;
}

char * multbignums(char *str1, char *str2, int size)
{
	char temp[size*9], zero[size*9], one[size*9];
	int i;
	for(i = 0; i<size*9; i++) zero[i] = '0';
	
	setbignums(temp, str1, size);
	setbignums(str1, zero, size);
	setbignums(one, zero, size);
	one[size*9-1] = '1';

	while(compbignums(temp, zero, size) != 0)
	{
		addbignums(str1, str2, size);
		subbignums(temp, one, size);
	}
	
	return str1;
}

char * divbignums(char *str1, char *str2, int decplace, int size)
{
	char abagilion[size*9], temp[size*9], one[size*9], zero[size*9];
	int i;
	for(i = 0; i<size*9; i++)
	{
		abagilion[i] = '0';
		temp[i] = '0';
		one[i] = '0';
		zero[i] = '0';
	}
	abagilion[9*size-decplace*9] = '1';
	one[size*9-1] = '1';

	while(compbignums(str1, str2, size) == 0 || compbignums(str1, str2, size) == 1)
	{	
		subbignums(str1, str2, size);
		addbignums(temp, one, size);
	}
	setbignums(str1, temp, size);
	
	return str1;
}