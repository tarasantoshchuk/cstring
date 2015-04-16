/**
* @file		MyStringUtil.c
* @brief	Implementation of MyStringUtil.h
*/
#include "MyStringUtil.h"

char* strconvert(char* str)
{
	char* curStr = (char*)str;
	while (*curStr)
	{
		curStr++;
	}
	*curStr = END_CHAR;
	return str;
}

int myputs(const char* str)
{
	size_t result = 0;
	while (*str != END_CHAR)
	{
		putchar(*str++);
		result++;
	}
	putchar('\n');
	return result;
}
