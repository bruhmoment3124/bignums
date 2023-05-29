#include <stdio.h>
#include "bignums.h"

int main(void)
{
	char zero[901];
	int i;
	for(i = 0; i<901; i++) zero[i] = '0';
	zero[75*9] = '.';
	
	char sq[901];
	setbignums(sq, zero, 100);
	sq[75*9-1] = '2';
	
	char est[901];
	setbignums(est, zero, 100);
	est[75*9-1] = '2';
	
	char half[901];
	setbignums(half, zero, 100);
	half[75*9-1] = '2';
	
	while(1)
	{
		char temp[901];
		setbignums(temp, sq, 100);
		
		divbignums(temp, est, 75, 100);
		addbignums(temp, est, 75, 100);
		divbignums(temp, half, 75, 100);
		setbignums(est, temp, 100);
		
		int i;
		for(i = 0; i<901; i++) printf("%c", est[i]);
		printf("\n");
		getchar();
	}
	
	return 0;
}