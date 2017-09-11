#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

char * strstr1(const char *str, const char *substr)
{
	assert(str && substr);

	if(!*substr)
		return (char *)str;

	char *ptr1 = (char *)str, *ptr2 = (char *)substr;

	while(*ptr1){
		if(*ptr1 != *ptr2)
		{
			++ptr1;
			continue;
		}
		char *ptr = ptr1;
		while(1){
			if(*ptr1 != *ptr2)
				break;
			if(0 == *ptr2)
				return ptr;
			ptr1++;
			ptr2++;
		}
		ptr1 = ptr+1;
		ptr2 = (char *)substr;
	}
	return NULL;
}
int main()
{
	if(strstr1("sol", ""))
		printf("Match found\n");
	else
		printf("Not found\n");
	return 0;
}

