#include <stdio.h>
#include "bignums.h"

int main(void)
{
	FILE *file = fopen("fib.txt", "w");
	
	static int t1[210000] = {0}, t2[210000] = {0}, nextterm[210000] = {0}, zero[210000] = {0};
	t1[209999] = 0;
	t2[209999] = 1;
	
	addbignums(nextterm, t1, 210000);
	addbignums(nextterm, t2, 210000);
	
	int i;
	for(i = 0; i<1000000; i++)
	{
		setbignums(t1, t2, 210000);
		setbignums(t2, nextterm, 210000);
		
		setbignums(nextterm, nextterm, 210000);
		addbignums(nextterm, t1, 210000);
		addbignums(nextterm, t2, 210000);
		printf("i: %d\n", i);
	}
	
	int j;
	for(j = 0; j<210000; j++) putc(t1[j]+48, file);
	printf("done.\n");
	fclose(file);
	
	getchar();
	
	return 0;
}