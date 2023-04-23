#include <stdio.h>
#include "bignums.h"

int main(void)
{
	char first[9] = "000000000", second[9] = "000000001", result[9] = "000000000";
	
	int i;
	for(i = 1; i<25; i++)
	{
		char temp[9] = "000000000";
		addbignums(temp, first, 1);
		addbignums(temp, second, 1);
		setbignums(result, temp, 1);
		
		setbignums(first, second, 1);
		setbignums(second, result, 1);
	}
	
	int j;
	for(j = 0; j<9; j++) printf("%c", result[j]);
	printf("\n");
	getchar();
	
	return 0;
}