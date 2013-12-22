#include <stdio.h>
#include <stdlib.h>

void MMAmemmove(void* dest, void const* src, int numBytes)
{
	register char const* sp = src;
	register char* dp = dest;
	if(dp < sp)
	{
		while(numBytes-- > 0)
		{
			*(dp++) = *(sp++);
		}
	}
	else 
	{
		dp += numBytes;
		sp += numBytes;
		while(numBytes-- > 0)
		{
			*(--dp) = *(--sp);
		}
	}
}
