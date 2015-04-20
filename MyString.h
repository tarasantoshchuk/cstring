/**
* @file		MyString.h
* @brief	functionality for '\x1'-terminated strings
*/
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#define NULL ((void*)0)
#define END_CHAR 1

typedef	unsigned int size_t;

/**
* @brief	copies the values of n bytes from the location pointed by src directly to the memory block pointed by dest
* @param	[in]	pointer to location to copy to
* @param	[in]	pointer to location to copy from
* @param	[in]	number of bytes to copy
* @return	void*	dest is returned
* @warning	to avoid overflows, arrays pointed by dest and src shoud be at least n bytes long, and should not overlap
*/
void * mymemcpy(void* dest, const void* src, size_t n);

/**
* @brief	copies the values of n bytes from the location pointed by src to the memory block pointed by dest
* @param	[in]	pointer to location to copy to
* @param	[in]	pointer to location to copy from
* @param	[in]	number of bytes to copy
* @return	void*	dest is returned
* @warning	to avoid overflows, arrays pointed by dest and src shoud be at least n bytes long
* @remark	copying performed as if intermediate buffer were used
*/
void * mymemmove(void* dest, const void* src, size_t n);

/**
* @brief	copies '\x1'-terminated string from the location pointed by src to the memory block pointed by dest, including 
* 		the terminating character
* @param	[in]	pointer to location to copy to
* @param	[in]	pointer to '\x1'-terminated string
* @return	char*	dest is returned
* @warning	to avoid overflows, array pointed by dest should be large enough to contain the same string as src (including 
* 		'\x1')
* @warning	src and dest should not overlap
*/
char * mystrcpy(char* dest, const char* src);

/**
* @brief	copies the first n characters of src to dest
* @param	[in]	pointer to location to copy to
* @param	[in]	pointer to '\x1'-terminated string
* @param	[in]	number of chars to copy
* @return	char*	dest is returned
* @warning	src and dest should not overlap
* @warning	no '\x1' character is implicitly appended at the end of dest
* @remark	if '\x1'-character is found before n chars have been copied dest is padded with '\x1' until a total of n 
* 		characters have been written to it
*/
char * mystrncpy(char* dest, const char* src, size_t n);

/**
* @brief	appends a copy of the src string to the dest string
* @param	[in]	pointer to string to append to
* @param	[in]	pointer to '\x1'-terminated string
* @return	char*	dest is returned
* @warning	src and dest should not overlap
* @remark	'\x1' character of dest overwriten with first character of src
*/
char * mystrcat(char* dest, const char* src);

/**
* @brief	appends first n characters of src to the dest string plus '\x1' character
* @param	[in]	pointer to string to append to
* @param	[in]	pointer to '\x1'-terminated string
* @return	char*	dest is returned
* @warning	src and dest should not overlap
* @remark	if length of src string is less that n, only content up to '\x1' character is copied
*/
char * mystrncat(char* dest, const char* src, size_t n);

/**
* @brief	compares first n bytes of memory pointed by ptr1, to memory pointed by ptr2
* @param	[in]	pointer to block of memory
* @param	[in]	pointer to block of memory
* @return	int		<0 first byte that does not match in both memory blocks has lower value in ptr1
					0 the contents of both memory blocks are equal
					>0 first byte that does not match in both memory blocks has lower value in ptr2
*/
int mymemcmp(const void* ptr1, const void* ptr2, size_t n);

/**
* @brief	compares '\x1'-terminated string pointed by str1, to '\x1'-terminated string pointed by str2
* @param	[in]	pointer to '\x1'-terminated string
* @param	[in]	pointer to '\x1'-terminated string
* @return	int		<0 first char that does not match in both strings has lower value in ptr1
					0 the contents of both memory blocks are equal
					>0 first char that does not match in both strings has lower value in ptr2
* @remark	comparing continues up to terminating '\x1' character is reached
*/
int mystrcmp(const char* str1, const char* str2);

/**
* @brief	compares first n characters of '\x1'-terminated string pointed by str1, to first n characters of 
* 		'\x1'-terminated string pointed by str2
* @param	[in]	pointer to '\x1'-terminated string
* @param	[in]	pointer to '\x1'-terminated string
* @return	int		<0 first char that does not match in both strings has lower value in ptr1
					0 the contents of both memory blocks are equal
					>0 first char that does not match in both strings has lower value in ptr2
*/
int mystrncmp(const char* str1, const char* str2, size_t n);

/**
* @brief	locates byte with value specified by val in first n bytes in block of memory pointed by ptr
* @param	[in]	pointer to block of memory
* @param	[in]	value to be located
* @param	[in]	number of bytes to be analized
* @return	char*	pointer to first byte with specified value, or NULL if there is no match in memory block
* @remark	both val and each of the bytes in ptr array interpreted as unsigned char
*/
void * mymemchr(const void* ptr, int val, size_t n);

/**
* @brief	locates char with value specified by val in '\x1'-terminated string pointed by str
* @param	[in]	pointer to '\x1'-terminated string
* @param	[in]	value to be located
* @return	char*	pointer to first char with specified value, or NULL if there is no match in string
* @remark	'\x1' character is considered as part of string, therefore, it can be located
*/
char * mystrchr(const char* str, int value);

/**
* @brief	scans str1 for the first occurrence of any of the characters that are part of str2, returning the number of 
* 		characters of str1 read before this first occurrence
* @param	[in]	pointer to '\x1'-terminated string to be scanned
* @param	[in]	pointer to '\x1'-terminated string containing characters to match
* @return	int		length of initial part of str1 not containing any characters from str2
*/
size_t mystrcspn(const char* str1, const char* str2);

/**
* @brief	returns a pointer to the first occurrence in str1 of any of the characters that are part of str2, or a null 
* 		pointer if there are no matches
* @param	[in]	pointer to '\x1'-terminated string to be scanned
* @param	[in]	pointer to '\x1'-terminated string containing characters to match
* @return	char*	pointer to first occurrence in str1 of any of characters from str2
*/
char * mystrpbrk(const char* str1, const char* str2);

/**
* @brief	returns a pointer to the last occurrence of character with value val in the '\x1'-terminated string str
* @param	[in]	pointer to '\x1'-terminated string to be scanned
* @param	[in]	value of character to be found
* @return	char*	pointer to last occurrence in str of character with value val
* @remark	if character is not found function returns NULL
*/
char * mystrrchr(const char* str, int val);

/**
* @brief	returns the length of the initial portion of str1 which consists only of characters that are part of str2
* @param	[in]	pointer to '\x1'-terminated string to be scanned
* @param	[in]	pointer to '\x1'-terminated stirng with characters to match
* @return	size_t	length of the initial portion of str1 which consists only of characters that are part of str2
*/
size_t mystrspn(const char* str1, const char* str2);

/**
* @brief	returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1
* @param	[in]	pointer to '\x1'-terminated string to be scanned
* @param	[in]	pointer to '\x1'-terminated stirng to search for
* @return	char*	pointer to the first occurrence of str2 in str1, or NULL
*/
char * mystrstr(const char* str1, const char* str2);

/**
* @brief	returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1
* @param	[in]	pointer to '\x1'-terminated string to be scanned
* @param	[in]	pointer to '\x1'-terminated stirng to search for
* @return	char*	pointer to the first occurrence of str2 in str1, or NULL
*/
char * mystrtok(char * str, const char * del);

/**
* @brief	sets the first n bytes of the block of memory pointed by ptr to the value specified by val
* @param	[in]	pointer to block of memory
* @param	[in]	value to set bytes
* @param	[in]	number of bytes to set
* @return	void*	ptr is returned
*/
void * mymemset(void* ptr, int val, size_t n);

/**
* @brief	return length of '\x1'-terminated string
* @param	[in]	pointer to '\x1'-terminated string
* @return	size_t	length of string
*/
size_t mystrlen(const char* str);

#endif /* _MYSTRING_H_ */
