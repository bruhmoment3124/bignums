#include <stdio.h>
#include "bignums.h"

int main(void)
{
	static int n1[2] = {0}, n2[2] = {0}, n3[2] = {0}, zero[2] = {0}; 
	n1[1] = 0;
	n2[1] = 1;
	
	int i;
	for(i = 1; i<75; i++)
	{
		setbignums(n3, zero, 2);
		addbignums(n3, n1, 2);
		addbignums(n3, n2, 2);
		
		setbignums(n1, n2, 2);
		setbignums(n2, n3, 2);
	}
	
	int j;
	for(j = 0; j<2; j++) printf("%09d", n3[j]);
	printf("\n");
	
	getchar();
	
	return 0;
}