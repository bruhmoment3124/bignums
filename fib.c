#include <stdio.h>
#include "bignums.h"

int main(void)
{
	char first[19] = "000000000.000000000", second[19] = "000000001.000000000", result[19] = "000000000.000000000";
	
	int i;
	for(i = 1; i<25; i++)
	{
		char temp[19] = "000000000.000000000";
		addbignums(temp, first, 1, 2);
		addbignums(temp, second, 1, 2);
		setbignums(result, temp, 2);
		
		setbignums(first, second, 2);
		setbignums(second, result, 2);
	}
	
	int j;
	for(j = 0; j<19; j++) printf("%c", result[j]);
	printf("\n");
	getchar();
	
	return 0;
}