/**
* @file		MyStringUtil.h
* @brief	Additional functions to work with mystring library
*
*/
#ifndef _MYSTRINGUTIL_H_
#define _MYSTRINGUTIL_H_

#include "MyString.h"

/**
* @brief	Convert '\0'-terminated string str to '\x1'-terminated string
* @param	[in, out]	'\0'-terminated string
* @return	char*	'\x1'-terminated string
*/
char * strconvert(char * str);

/**
* @brief	print '\x1'-terminated string to stdout
* @param	[in]	'\0'-terminated string
* @return	int		number of characters printed
*/
int myputs(const char * str);

#endif /* _MYSTRINGUTIL_H */
