#include <math.h>

/*************************
* string-number operations
/************************/

void strtonum(char *str, int *arr, int size)
{
	char temp[size*9];
	
	int i, decplacejump = 0;
	for(i = 0; i<size*9; i++)
	{
		temp[i] = '0';
		
		if(str[i] == '.') decplacejump++;
		temp[i] = str[i+decplacejump];
	}

	int j, k;
	for(j = 1; j<=size; j++)
	{
		for(k = 8; k>=0; k--)
		{	
			arr[j-1] += (temp[(9*j-k)-1]-48)*pow((double)10, (double)k);
		}
	}
}

void numtostr(int *arr, char *str, int decplace, int size)
{
	int i, j, decplacejump = 0;
	for(i = 1; i<=size; i++)
	{
		for(j = 8; j>=0; j--)
		{
			if((9*i-j)-1 == decplace*9) decplacejump++;
			str[(9*i-j)-1+decplacejump] = ((int)floor(arr[i-1] / pow((double)10, (double)j)) % 10)+48;
		}
	}
	str[9*decplace] = '.';
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

void setbignums(char *str1, char *str2, int size)
{
	int i;
	for(i = 0; i<size*9+1; i++) str1[i] = str2[i];
}

/**********************
* comparison operations
/*********************/

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

	int i;
	for(i = 0; i<size; i++) arr[i] = 0;
	strtonum(str1, arr, size);
	
	if(arr[size-1] % 2 == 0) return 0;
	
	return 1;
}

/**********************
* arithmetic operations
/*********************/

void addbignums(char *str1, char *str2, int decplace, int size)
{	
	/* arrays to hold string values*/
	int arr1[size], arr2[size];

	/* fill arrays with zeros */
	int i;
	for(i = 0; i<size; i++)
	{
		arr1[i] = 0;
		arr2[i] = 0;
	}

	/* convert string value and hold in the arrays */
	strtonum(str1, arr1, size);
	strtonum(str2, arr2, size);

	/* add each segment of the arrays together */
	int j;
	for(j = 0; j<size; j++) arr1[j] += arr2[j];
	
	int k;
	for(k = size-1; k>=0; k--) 
	{
		/* arrays held in segments of 9 digits each, add one when over 9 digits */
		if(arr1[k] >= 1000000000)
		{
			arr1[k-1]++; /* carry the value over */
			arr1[k] -= 1000000000; /* reset current value by difference overflown */
		}
	}
	
	/* convert the array back into a string */
	numtostr(arr1, str1, decplace, size);
}

void subbignums(char *str1, char *str2, int decplace, int size)
{
	/* arrays to hold string values*/
	int arr1[size], arr2[size];

	/* fill arrays with zeros */
	int i;
	for(i = 0; i<size; i++)
	{
		arr1[i] = 0;
		arr2[i] = 0;
	}

	/* convert string value and hold in the arrays */
	strtonum(str1, arr1, size);
	strtonum(str2, arr2, size);

	/* subtract each segment of the arrays from one another */
	int j;
	for(j = 0; j<size; j++) arr1[j] -= arr2[j];
	
	int k;
	for(k = size-1; k>=0; k--)
	{
		/* arrays held in segments of 9 digits each. When below 0, subtract nearest digit by one
		   and reset */
		if(arr1[k] < 0)
		{
			arr1[k-1]--; /* subtract 1 from nearest place */
			arr1[k] += 1000000000; /* reset difference by amount below 0 */
		}
	}
	
	/* convert the array back into a string */
	numtostr(arr1, str1, decplace, size);
}

void multbignums(char *str1, char *str2, int decplace, int size)
{	
	char strsave[size*9+1];
	setbignums(strsave, str2, size);
	
	int decend = 0, decsize = 0;
	
	int i;
	for(i = size*9; i>=decplace*9; i--)
	{
		if(decend == 0 && str2[i] >= 49 && str2[i] <= 57) decend = i;
	}
	if(decend > 0) decsize = decend-decplace*9;
	
	int j;
	for(j = 0; j<decsize; j++) shiftbignums(str1, 1, size);
	
	int k;
	for(k = 0; k<size*9-(decplace*9+decsize); k++) shiftbignums(str2, 1, size);
	
	char half[size*9+1], zero[size*9+1], prod[size*9+1], dbl[size*9+1];
	
	int l;
	for(l = 0; l<size*9+1; l++) zero[l] = '0';
	zero[9*decplace] = '.';
	setbignums(prod, zero, size);
	
	while(compbignums(str2, zero, size) == 1)
	{	
		if(paritybignums(str2, size) == 1) addbignums(prod, str1, decplace, size);
		
		setbignums(dbl, str1, size);
		addbignums(str1, dbl, decplace, size);
		
		setbignums(half, str2, size);
		int m;
		for(m = 0; m<4; m++) addbignums(str2, half, decplace, size);
		shiftbignums(str2, 1, size);
	}
	setbignums(str1, prod, size);
	setbignums(str2, strsave, size);
}

void divbignums(char *str1, char *str2, int decplace, int size)
{
	char strsave[size*9+1];
	setbignums(strsave, str2, size);
	
	int decend = 0, decsize = 0;
	
	int i;
	for(i = size*9; i>=decplace*9; i--)
	{
		if(decend == 0 && str2[i] >= 49 && str2[i] <= 57) decend = i;
	}
	if(decend > 0) decsize = decend-decplace*9;
	
	int j;
	for(j = 0; j<decsize; j++) shiftbignums(str1, -1, size);
	
	int k;
	for(k = 0; k<size*9-(decplace*9+decsize); k++) shiftbignums(str2, 1, size);
	
	char quot[size*9+1], pow2[size*9+1], one[size*9+1], zero[size*9+1];
	
	int l;
	for(l = 0; l<size*9+1; l++) zero[l] = '0';
	zero[decplace*9] = '.';
	
	setbignums(quot, zero, size);
	
	setbignums(one, zero, size);
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
	
	while(compbignums(pow2, zero, size) != 0)
	{
		char temp1[size*9+1], temp2[size*9+1];
		setbignums(temp1, dbl, size);
		setbignums(temp2, pow2, size);
		
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
		
		int m;
		for(m = 0; m<4; m++)
		{	
			addbignums(dbl, temp1, decplace, size);
			addbignums(pow2, temp2, decplace, size);
		}
		shiftbignums(dbl, 1, size);
		shiftbignums(pow2, 1, size);
	}
	setbignums(str1, quot, size);
	setbignums(str2, strsave, size);
}

/**********
* fractions
/*********/

void addfrac(char *str1, char *str2, char *str3, char *str4, int decplace, int size)
{
	multbignums(str1, str4, decplace, size);
	multbignums(str3, str2, decplace, size);
	addbignums(str1, str3, decplace, size);
	
	multbignums(str2, str4, decplace, size);
}

void multfrac(char *str1, char *str2, char *str3, char *str4, int decplace, int size)
{  
	multbignums(str1, str3, decplace, size);
	multbignums(str2, str4, decplace, size);
}

void divfrac(char *str1, char *str2, char *str3, char *str4, int decplace, int size)
{   
	multbignums(str1, str4, decplace, size);
	multbignums(str2, str3, decplace, size);
}