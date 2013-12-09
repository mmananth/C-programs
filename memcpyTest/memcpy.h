void *mmaMemCpy(void* dest, const void* src, int numBytes)
{
	char* dp = dest;
	const char* sp = src;
	while(numBytes--)
	{
		*dp++ = *sp++;
	}
	return dest;
}
