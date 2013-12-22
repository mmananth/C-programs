#include "memmove.h"

int main()
{
	char* srcStr = "Hello";
	char* destStr = malloc(sizeof(srcStr)+1);
	MMAmemmove(destStr, srcStr, sizeof(srcStr)+1);
	/*if(retVal != sizeof(srcStr))
		perror("Mem move did not succeed");
	else
		printf("Mem move succeeded");*/

	printf("srcStr is: %s\n", srcStr);
	printf("destStr is: %s\n", destStr);
	return 0;
}
