#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isSteppingNumber(int num)
{
	int prev_digit = -1;
	int curr_digit;
	while(num){
		curr_digit = num%10;
		if(prev_digit != -1)
		{
			if(abs(curr_digit-prev_digit) != 1)
				return false;
		}
		prev_digit = curr_digit;
		num = num/10;
	}
	return true;
}
int main()
{
	int n = 0, m = 12345678;
	for(int i = n; i <=m; ++i) {
		if(isSteppingNumber(i))
			printf("%d ", i);
	}
	printf("\n");
	return 0;	
}
