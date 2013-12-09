#include <stdio.h>

int main()
{
	int firstValue = 5, secondValue = 15;
	int *p1, *p2;

	p1 = &firstValue;
	p2 = &secondValue;

	*p1 = 10;
	*p2 = *p1;

	p1 = p2;
	*p1 = 20;

	printf("firstValue = %d, secondValue = %d \n", *p1, *p2);
	return 0;
}
