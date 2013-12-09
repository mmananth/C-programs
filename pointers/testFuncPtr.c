#include <stdio.h>

int addition(int a, int b)
{
	return(a + b);
}

int subtraction(int a, int b)
{
	return(a > b?(a-b):(b-a));
}

int operation(int a, int b, int (*func)(int, int))
{
	return (*func)(a, b);
}

int main()
{
	int a = 5, b = 10;
	int (*minus)(int,int) = subtraction;
	int resultSum = operation(a, b, addition);	
	int resultMinus = operation(a, b, minus);	
	printf("sum is: %d\n", resultSum);
	printf("subtraction is: %d\n", resultMinus);
	return 0;
}
