#include <stdio.h>
#include "bignums.h"

int main(void)
{
	static int n1[100] = {0}, n2[100] = {0}, n3[100] = {0}, zero[100] = {0}; 
	n1[99] = 0;
	n2[99] = 1;
	
	int i;
	for(i = 1; i<2000; i++)
	{
		setbignums(n3, zero, 100);
		addbignums(n3, n1, 100);
		addbignums(n3, n2, 100);
		
		setbignums(n1, n2, 100);
		setbignums(n2, n3, 100);
	}
	
	int j;
	for(j = 0; j<100; j++) printf("%09d", n3[j]);
	printf("\n");
	
	getchar();
	
	return 0;
}