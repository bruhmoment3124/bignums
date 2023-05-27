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

void numtostr(int *arr, char *str, int decplace, int size)
{
	int i, k, x = 0;
	for(i = 1; i<=size; i++)
	{
		for(k = 8; k>=0; k--)
		{
			if((9*i-k)-1 == decplace*9) x++;
			str[(9*i-k)-1+x] = ((int)floor(arr[i-1] / pow((double)10, (double)k)) % 10)+48;
		}
	}
	str[9*decplace] = '.';
}

int sizeofstr(char *str)
{
	int n = 0;
	
	int i;
	for(i = 0; str[i] != '\0'; i++) n++;

	return n;
}

void shiftbignums(char *str, int n, int size)
{
	int i, j;
	if(n == 1)
	{
		for(i = size*9; i>=0; i--)
		{
			if(str[i] == '.')
			{
				str[i+1] = str[i-1];
				str[i-1] = '0';
			}
			
			if(str[i] >= 49 && str[i] <= 57)
			{
				str[i+1] = str[i];
				str[i] = '0';
			}
		}
	} else if(n == -1)
	{
		for(j = 0; j<size*9+1; j++)
		{
			if(str[j] == '.')
			{
				str[j-1] = str[j+1];
				str[j+1] = '0';
			}
			
			if(str[j] >= 49 && str[j] <= 57)
			{
				str[j-1] = str[j];
				str[j] = '0';
			}
		}
	}
}

char * setbignums(char *str1, char *str2, int size)
{
	int i;
	for(i = 0; i<size*9+1; i++) str1[i] = str2[i];
	
	return str1;
}

int compbignums(char *str1, char *str2, int size)
{	
	int i;
	for(i = 0; i<size*9+1; i++)
	{
		int x = str1[i] - 48;
		int y = str2[i] - 48;
		
		if(x > y)
		{
			return 1;
		} else if(x < y)
		{
			return 2;
		}
	}
	
	return 0;
}

int paritybignums(char *str1, int size)
{
	int arr[size];

	int l;
	for(l = 0; l<size; l++) arr[l] = 0;
	strtonum(str1, arr, size);
	
	if(arr[size-1] % 2 == 0) return 0;
	
	return 1;
}

char * addbignums(char *str1, char *str2, int decplace, int size)
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
	numtostr(arr1, str1, decplace, size);
	
	return str1;
}

char * subbignums(char *str1, char *str2, int decplace, int size)
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
	numtostr(arr1, str1, decplace, size);
	
	return str1;
}

char * multbignums(char *str1, char *str2, int decplace, int size)
{	
	char strsave[size*9+1];
	setbignums(strsave, str2, size);
	
	int decend = 0, decsize = 0;
	
	int j;
	for(j = size*9; j>=decplace*9; j--)
	{
		if(decend == 0 && str2[j] >= 49 && str2[j] <= 57) decend = j;
	}
	if(decend > 0) decsize = decend-decplace*9;
	
	int g;
	for(g = 0; g<decsize; g++) shiftbignums(str1, 1, size);
	
	int p;
	for(p = 0; p<size*9-(decplace*9+decsize); p++) shiftbignums(str2, 1, size);
	
	char half[size*9+1], zero[size*9+1], prod[size*9+1], dbl[size*9+1];
	
	int i;
	for(i = 0; i<size*9+1; i++) zero[i] = '0';
	zero[9*decplace] = '.';
	setbignums(prod, zero, size);
	
	while(compbignums(str2, zero, size) == 1)
	{	
		if(paritybignums(str2, size) == 1) addbignums(prod, str1, decplace, size);
		
		setbignums(dbl, str1, size);
		addbignums(str1, dbl, decplace, size);
		
		setbignums(half, str2, size);
		int l;
		for(l = 0; l<4; l++) addbignums(str2, half, decplace, size);
		shiftbignums(str2, 1, size);
	}
	setbignums(str1, prod, size);
	setbignums(str2, strsave, size);
	
	return str1;
}

char * divbignums(char *str1, char *str2, int decplace, int size)
{
	char strsave[size*9+1];
	setbignums(strsave, str2, size);
	
	int decend = 0, decsize = 0;
	
	int j;
	for(j = size*9; j>=decplace*9; j--)
	{
		if(decend == 0 && str2[j] >= 49 && str2[j] <= 57) decend = j;
	}
	if(decend > 0) decsize = decend-decplace*9;
	
	int g;
	for(g = 0; g<decsize; g++) shiftbignums(str1, -1, size);
	
	int p;
	for(p = 0; p<size*9-(decplace*9+decsize); p++) shiftbignums(str2, 1, size);
	
	char quot[size*9+1], pow2[size*9+1], one[size*9+1];
	
	int i;
	for(i = 0; i<size*9+1; i++) one[i] = '0';
	one[decplace*9] = '.';
	
	setbignums(quot, one, size);
	
	one[size*9] = '1';
	setbignums(pow2, one, size);
	
	char dbl[size*9+1];
	setbignums(dbl, str2, size);
	
	while(compbignums(dbl, str1, size) == 2)
	{	
		char temp1[size*9+1], temp2[size*9+1];
		setbignums(temp1, dbl, size);
		setbignums(temp2, pow2, size);
		
		addbignums(dbl, temp1, decplace, size);
		addbignums(pow2, temp2, decplace, size);
	}
	
	char combtemp[size*9+1];
	setbignums(combtemp, one, size);
	combtemp[size*9] = '0';
	
	while(compbignums(pow2, one, size) != 0)
	{
		char combtemp2[size*9+1];
		
		setbignums(combtemp2, one, size);
		combtemp2[size*9] = '0';
		
		addbignums(combtemp2, combtemp, decplace, size);
		addbignums(combtemp2, dbl, decplace, size);
	
		if(compbignums(str1, combtemp2, size) < 2)
		{
			addbignums(combtemp, dbl, decplace, size);
			addbignums(quot, pow2, decplace, size);
		}
		
		char temp1[size*9+1], temp2[size*9+1];
		setbignums(temp1, dbl, size);
		setbignums(temp2, pow2, size);
		
		int l;
		for(l = 0; l<4; l++)
		{	
			addbignums(dbl, temp1, decplace, size);
			addbignums(pow2, temp2, decplace, size);
		}
		shiftbignums(dbl, 1, size);
		shiftbignums(pow2, 1, size);
	}
	setbignums(str1, quot, size);
	setbignums(str2, strsave, size);

	return str1;
}