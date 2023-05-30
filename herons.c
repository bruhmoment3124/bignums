#include <stdio.h>
#include "bignums.h"

int main(void)
{
	char zero[1801];
	int i;
	for(i = 0; i<1801; i++) zero[i] = '0';
	zero[101*9] = '.';
	
	char sq[1801];
	setbignums(sq, zero, 200);
	sq[101*9-1] = '2';
	
	char est[1801];
	setbignums(est, zero, 200);
	est[101*9-1] = '2';
	
	char half[1801];
	setbignums(half, zero, 200);
	half[101*9-1] = '2';
	
	while(1)
	{
		char temp[1801];
		setbignums(temp, sq, 200);
		
		divbignums(temp, est, 101, 200);
		addbignums(temp, est, 101, 200);
		divbignums(temp, half, 101, 200);
		setbignums(est, temp, 200);
		
		int i;
		for(i = 0; i<1801; i++) printf("%c", est[i]);
		printf("\n\n");
	}
	
	return 0;
}