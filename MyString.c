/**
* @file		MyString.c
* @brief	Implementation of MyString.h
*/
#include "MyString.h"

// copying functions

void* mymemcpy(void* dest, const void* src, size_t n)
{
	char* curDest = (char*)dest;
	const char* curSrc = (const char*)src;
	//increase n to use pre-decrement in while loop
	++n;
	//copy n bytes from src to dest
	while (--n)
	{
		*curDest++ = *curSrc++;
	}
	return dest;
}

void* mymemmove(void* dest, const void* src, size_t n)
{
	//to copy correctly (in case of blocks overlapping) we need to copy from first to last byte if
	//dest < src, and from last to first if dest > src
	if (dest < src)
	{
		char* curDest = (char*)dest;
		char* curSrc = (char*)src;
		//increase n to use pre-decrement in while loop
		++n;
		while (--n)
		{
			*curDest++ = *curSrc++;
		}
	}
	else if (dest > src)
	{
		char* curDest = (char*)dest + n - 1;
		char* curSrc = (char*)src + n - 1;
		//increase n to use pre-decrement in while loop
		++n;
		while (--n)
		{
			*curDest-- = *curSrc--;
		}
	}
	return dest;
}

char* mystrcpy(char* dest, const char* src)
{
	char* curDest = dest;
	//copy bytes until end of src string
	while (*src != END_CHAR)
	{
		*curDest++ = *src++;
	}
	*curDest = END_CHAR;
	return dest;
}

char* mystrncpy(char* dest, const char* src, size_t n)
{
	char* curDest = dest;
	//increase n to use pre-decrement in while loop
	++n;
	while (--n && (*src != END_CHAR))
	{
		*curDest++ = *src++;
	}
	//fill the rest with END_CHAR
	for (size_t i = n; i > 0; --i)
	{
		*curDest++ = END_CHAR;
	}
	return dest;
}

// concatenating functions

char* mystrcat(char* dest, const char* src)
{
	char* curDest = dest;
	//set curDest to end of dest
	curDest += mystrlen(dest);
	//copy src
	while (*src != END_CHAR)
	{
		*curDest++ = *src++;
	}
	*curDest = END_CHAR;
	return dest;
}

char* mystrncat(char* dest, const char* src, size_t n)
{
	char * curDest = dest;
	curDest += mystrlen(dest);
	//increase n to use pre-increment in while loop
	++n;
	//until n chars copied or end of src reached 
	while(--n && (*src != END_CHAR))
	{
		*curDest++ = *src++;
	}
	*curDest = END_CHAR;
	return dest;
}

// comparing functions

int mymemcmp(const void* ptr1, const void* ptr2, size_t n)
{
	size_t i = 1;
	const char* curPtr1 = (const char*)ptr1;
	const char* curPtr2 = (const char*)ptr2;
	//find first mismatch in first n bytes if any
	while (i < n && (*curPtr1 == *curPtr2))
	{
		i++;
		curPtr1++;
		curPtr2++;
	}
	return *curPtr1 - *curPtr2;
}

int mystrcmp(const char* str1, const char* str2)
{
	//find first mismatch or end of str1
	//if str2 ends then either *str1 != *str2 - we found mismatch,
	//or *str1 == *str2 == END_CHAR - in both cases while loop ends
	while ((*str1 != END_CHAR) && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int mystrncmp(const char* str1, const char* str2, size_t n)
{
	size_t i = 1;
	//find mismatch in first n chars and before end of strings
	while ((i < n) && (*str1 != END_CHAR) && (*str1 == *str2))
	{
		i++;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

// searching functions

void* mymemchr(const void* ptr, int value, size_t n)
{
	char* curPtr = (char*)ptr;
	//increase n to use pre-decrement in while loop
	++n;
	while (--n)
	{
		if (*curPtr == value)
		{
			return curPtr;
		}
		curPtr++;
	}
	return NULL;
}

char* mystrchr(const char* str, int value)
{
	//find match before end of str
	while (*str != END_CHAR)
	{
		if (*str == value)
		{
			return str;
		}
		str++;
	}
	//check for END_CHAR 
	if (value == END_CHAR)
	{
		return str;
	}
	//if no match was found
	return NULL;
}

size_t mystrcspn(const char* str1, const char* str2)
{
	const char* curStr1 = str1;
	//for each char in str1..
	while (*curStr1 != END_CHAR)
	{
		const char * curStr2 = str2;
		//for each char in str2..
		while (*curStr2 != END_CHAR)
		{
			//if chars are equal return number of chars scanned in str1
			if (*curStr1 == *curStr2)
			{
				return curStr1 - str1;
			}
			curStr2++;
		}
		curStr1++;
	}
	//if no matches (only END_CHARs)
	return curStr1 - str1;
}

char* mystrpbrk(const char* str1, const char* str2)
{
	//same as mystrcspn but returns pointer to char that match
	char* curStr1 = str1;
	while (*curStr1 != END_CHAR)
	{
		const char* curStr2 = str2;
		while (*curStr2 != END_CHAR)
		{
			if (*curStr1 == *curStr2)
			{
				return curStr1;
			}
			curStr2++;
		}
		curStr1++;
	}
	return NULL;
}

char* mystrrchr(const char* str, int val)
{
	//search from end to beginning
	char* curStr = str + mystrlen(str);
	while (curStr >= str)
	{
		if (*curStr == val)
		{
			return curStr;
		}
		--curStr;
	}
	return NULL;
}

size_t mystrspn(const char* str1, const char* str2)
{
	const char* curStr1 = str1;
	char flag;
	while (*curStr1 != END_CHAR)
	{
		//flag to indicate if *curStr1 is equal to any of chars from str2
		flag = 0;
		const char* curStr2 = str2;
		while (*curStr2 != END_CHAR)
		{
			if (*curStr1 == *curStr2)
			{
				flag = 1;
				break;
			}
			curStr2++;
		}
		//if curStr1 is not in str2 - initial portion of str1 which consists 
		//only of characters that are part of str2 ended
		if (!flag)
		{
			return curStr1 - str1;
		}
		curStr1++;
	}
	//if str1 is empty
	return 0;
}

char* mystrstr(const char* str1, const char* str2)
{
	char* curStr2;
	char* curStr1;
	//str1 equal to the first char where we check for str2 occurence
	while (*str1 != END_CHAR)
	{
		//set values for curStr1 and curStr2
		curStr1 = str1;
		curStr2 = str2;
		//till end of str2 or first mismatch
		while (*curStr2 != END_CHAR && *curStr1 == *curStr2)
		{
			curStr1++;
			curStr2++;
		}
		//check if we found str2 occurence
		if (*curStr2 == END_CHAR)
		{
			return str1;
		}
		//move to next char
		str1++;
	}
	return NULL;
}

char* mystrtok(char* str, const char* del)
{
	//variable to save start of token search
	static char* scanStart = NULL;
	//pointer to beginning to current token
	char* tokBegin;
	//if previous str ended and str == NULL
	if ((!scanStart || *scanStart == END_CHAR) && !str)
	{
		return NULL;
	}
	//if new str provided - change scanStart
	if (str)
	{
		scanStart = str;
	}
	//skip delimiters to find beginning of token
	scanStart += mystrspn(scanStart, del);
	tokBegin = scanStart;
	//find first occurrence of delimiter to find end of token
	scanStart += mystrcspn(scanStart, del);
	if (*scanStart == END_CHAR)
	{
		//if end of str
		scanStart = NULL;
	}
	else
	{
		//set char to END_CHAR to indicate end of string
		*scanStart++ = END_CHAR;
	}
	return tokBegin;
}

// other functions

void* mymemset(void* ptr, int value, size_t n)
{
	char* curPtr = (char*)ptr;
	//increase n to use pre-decrement in while loop
	++n;
	while (--n)
	{
		//to bytes to specified value
		*curPtr++ = value;
	}
	return ptr;
}

size_t mystrlen(const char* str)
{
	const char* curStr = str;
	//search end of str
	while (*curStr != END_CHAR)
	{
		++curStr;
	}
	//curStr - str is equal to length of str
	return curStr - str;
}

