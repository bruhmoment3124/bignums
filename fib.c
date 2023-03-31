#include <stdio.h>
#include "bignums.h"

int main(void)
{
	int t1[1000] = {0}, t2[1000] = {0}, nextterm[1000] = {0};
	t1[999] = 0;
	t2[999] = 1;
	
	addbignums(nextterm, t1, 1000);
	addbignums(nextterm, t2, 1000);
	
	int i;
	for(i = 0; i<2500; i++)
	{
		setbignums(t1, t2, 1000);
		setbignums(t2, nextterm, 1000);
		
		subbignums(nextterm, nextterm, 1000);
		addbignums(nextterm, t1, 1000);
		addbignums(nextterm, t2, 1000);
	}
	
	int j;
	for(j = 0; j<1000; j++) printf("%d", t1[j]);
	printf("\n");
	
	getchar();
	
	return 0;
}