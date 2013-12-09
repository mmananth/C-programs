#include "memcpy.h"
#include <stdio.h>

int main()
{
	char* srcStr = "test";
	char* destStr;
	
	printf("Size of srcStr: %d\n", sizeof(srcStr));
	mmaMemCpy(destStr, srcStr, sizeof(srcStr)+1);
	printf("The destStr is: %s\n", destStr);
	return 0;
}
