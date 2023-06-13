#include <stdio.h>
#include "bignums.h"

int main(void)
{
	char n[46] = "000000000000000000000000050.000000000000000000";
	
	char zero[46] = "000000000000000000000000000.000000000000000000";
	char one[46] = "000000000000000000000000001.000000000000000000";
	char two[46] = "000000000000000000000000002.000000000000000000";
	char four[46] = "000000000000000000000000004.000000000000000000";
	
	char denom[46];
	setbignums(denom, n, 5);
	multbignums(denom, two, 3, 5);
	addbignums(denom, one, 3, 5);
	
	while(compbignums(n, zero, 5) == 1)
	{
		char divadd[46], numer[46];
		setbignums(divadd, n, 5);
		multbignums(divadd, two, 3, 5);
		subbignums(divadd, one, 3, 5);
		
		setbignums(numer, n, 5);
		multbignums(numer, n, 3, 5);
		
		divbignums(numer, denom, 3, 5);
		addbignums(numer, divadd, 3, 5);
		setbignums(denom, numer, 5);
		
		subbignums(n, one, 3, 5);
	}
	
	divbignums(four, denom, 3, 5);
	int i;
	for(i = 0; i<46; i++) printf("%c", four[i]);
	printf("\n");
	getchar();
	
	return 0;
}