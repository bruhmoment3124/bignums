#include <stdio.h>
#include "bignums.h"

int main(void)
{
	FILE *f = fopen("fib.txt", "w");
	
	static int n1[210000] = {0}, n2[210000] = {0}, n3[210000] = {0}, zero[210000] = {0}; 
	n1[209999] = 0;
	n2[209999] = 1;
	
	int i;
	for(i = 1; i<1000000; i++)
	{
		setbignums(n3, zero, 210000);
		addbignums(n3, n1, 210000);
		addbignums(n3, n2, 210000);
		
		setbignums(n1, n2, 210000);
		setbignums(n2, n3, 210000);
		printf("%d\n", i);
	}
	
	int j;
	for(j = 0; j<210000; j++) putc(n3[j]+48, f);
	printf("\n");
	
	getchar();
	
	return 0;
}