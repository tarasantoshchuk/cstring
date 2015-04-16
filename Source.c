#include <time.h>
#include "MyString.h"
#include "MyStringUtil.h"

#define BIG_INT 100000000

//time test for key functions
void mymemcpyTimeTest()
{
	void* ptr1 = malloc(BIG_INT);
	void* ptr2 = malloc(BIG_INT);
	time_t t = clock();
	mymemcpy(ptr2, ptr1, BIG_INT);
	t = clock() - t;
	printf("mymemcpy time: %d\n", (long long)t);
	t = clock();
	memcpy(ptr2, ptr1, BIG_INT);
	t = clock() - t;
	printf("memcpy time: %d\n\n", (long long)t);
	free(ptr1);
	free(ptr2);
	_getch();
}
void mymemmoveTimeTest()
{
	void* ptr1 = malloc(BIG_INT + 1);
	time_t t = clock();
	mymemmove(ptr1, (char*)ptr1 + 1, BIG_INT);
	t = clock() - t;
	printf("mymemmove time: %d\n", (long long)t);
	t = clock();
	memmove(ptr1, (char*)ptr1 + 1, BIG_INT);
	t = clock() - t;
	printf("memmove time: %d\n\n", (long long)t);
	free(ptr1);
	_getch();
}
void mymemsetTimeTest()
{
	void* ptr1 = malloc(BIG_INT);
	time_t t = clock();
	mymemset(ptr1, 1, BIG_INT);
	t = clock() - t;
	printf("mymemset time: %d\n", (long long)t);
	t = clock();
	memset(ptr1, 1, BIG_INT);
	t = clock() - t;
	printf("memset time: %d\n\n", (long long)t);
	free(ptr1);
	_getch();
}

//copying functions tests
void mymemcpyTest()
{
	char* ptr1 = "some text..................\x1";
	char* ptr2 = (char*)malloc(mystrlen(ptr1));
	mymemcpy(ptr2, ptr1, mystrlen(ptr1) + 1);
	myputs("Mymemcpy test\nSource and destination respectively:\x1");
	myputs(ptr1);
	myputs(ptr2);
}
void mymemmoveTest()
{
	myputs("Mymemmove test\x1");
	char str[] = "memmove can be very useful......\x1";
	mymemmove(str + 20, str + 15, 11);
	// write result to stdout (should be "memmove can be very very useful.")
	myputs(str);
}
void mystrcpyTest()
{
	char str1[] = "some string";
	char* mystr1 = strconvert(str1);
	char* mystr2 = (char*)malloc(mystrlen(mystr1) + 1);
	mystrcpy(mystr2, mystr1);
	myputs("Mystrcpy test\nSource and destination strings:\x1");
	myputs(mystr1);
	myputs(mystr2);
}
void mystrncpyTest()
{
	char str1[] = "some string";
	char* mystr1 = strconvert(str1);
	char* mystr2 = (char*)malloc(mystrlen(mystr1) + 1);
	mystrncpy(mystr2, mystr1, 2);
	myputs("Mystrncpy test\nSource and destination strings:\x1");
	myputs("destination should contain first 2 characters from source and trash, because '\\x1' character is missing\x1");
	myputs(mystr1);
	myputs(mystr2);
}
//concatenating functions tests
void mystrcatTest()
{
	char str1[50] = "some string";
	char str2[50] = "some other string";
	char* mystr1 = strconvert(str1);
	char* mystr2 = strconvert(str2);
	myputs("Mystrcat test\nmystr1 and mystr2 strings:\x1");
	myputs(mystr1);
	myputs(mystr2);
	mystrcat(mystr1, mystr2);
	myputs("result of concatenation: \x1");
	myputs(mystr1);
}
void mystrncatTest()
{
	char str1[50] = "some string";
	char str2[50] = "some other string";
	char* mystr1 = strconvert(str1);
	char* mystr2 = strconvert(str2);
	myputs("Mystrncat test\nmystr1 and mystr2 strings:\x1");
	myputs(mystr1);
	myputs(mystr2);
	mystrncat(mystr2, mystr1, 7);
	myputs("result of concatenation of 7 characters: \x1");
	myputs(mystr2);
}
//comparing functions tests
void mymemcmpTest()
{
	char ptr1[50] = "asdfghjkl;";
	char ptr2[50] = "asdfghjkL ";
	int result = mymemcmp(ptr1, ptr2, 10);
	myputs("result of comparing first 10 bytes of 'asdfghjkl;' and 'asdfghjkL '\x1");
	printf("%d\n", result);
	result = mymemcmp(ptr1, ptr2, 5);
	myputs("result of comparing first 5 bytes of 'asdfghjkl;' and 'asdfghjkL '\x1");
	printf("%d", result);
}
void mystrcmpTest()
{
	char str1[50] = "asdfghjkL\x1";
	char str2[50] = "asdfghjkl\x1";
	char* mystr1 = strconvert(str1);
	char* mystr2 = strconvert(str2);
	int result = mystrcmp(mystr1, mystr2);
	myputs("Mystrcmp test\nresult of comparing strings: 'asdfghjkl;' and 'asdfghjkL '\x1");
	printf("%d\n", result);
}
void mystrncmpTest()
{
	char str1[50] = "asdfghjkl;\x1";
	char str2[50] = "asdfghjkL \x1";
	char* mystr1 = strconvert(str1);
	char* mystr2 = strconvert(str2);
	int result = mystrncmp(mystr1, mystr2, 5);
	myputs("Mystrncmp test\nresult of comparing first 5 chars of strings: 'asdfghjkl;' and 'asdfghjkL '\x1");
	printf("%d\n", result);
}
//searching functions tests
void mymemchrTest()
{
	char str[] = "qwertyuiop[]asdfg\x1";
	char value = 't';
	myputs("Mymemchr test\nstring, value to find and located value respectively:\x1");
	myputs(str);
	putchar(value);
	putchar('\n');
	putchar(*(char*)mymemchr(str, value, 9));
}
void mystrchrTest()
{
	char str[] = "qwertyuiop[]asdfg\x1";
	char value = 't';
	myputs("Mystrchr test\nstring, value to find and located value respectively:\x1");
	myputs(str);
	putchar(value);
	putchar('\n');
	putchar(*mystrchr(str, value, mystrlen(str)));
}
void mystrcspnTest()
{
	char str1[] = "qwertyuiop[]asdfg\x1";
	char str2[] = "p\x1";
	myputs("Mystrcspn test\nstr1, str2 and function result:\x1");
	myputs(str1);
	myputs(str2);
	printf("%d\n", mystrcspn(str1, str2));
}
void mystrpbrkTest()
{
	char str1[] = "qwertyuiop[]asdfg\x1";
	char str2[] = "et\x1";
	myputs("Mystrpbrk test\nstr1, str2 and indirected function result:\x1");
	myputs(str1);
	myputs(str2);
	putchar(*mystrpbrk(str1, str2));
}
void mystrrchrTest()
{
	char str[] = "qwertyuiop[]asdfgt\x1";
	char value = 't';
	myputs("Mystrrchr test\nstring, value to find and located value respectively:\x1");
	myputs(str);
	putchar(value);
	putchar('\n');
	putchar(*mystrrchr(str, value, mystrlen(str)));
}
void mystrspnTest()
{
	char str1[] = "qwertyuiop[]asdfg\x1";
	char str2[] = "qweyrtiaos\x1";
	myputs("Mystrspn test\nstr1, str2 and function result:\x1");
	myputs(str1);
	myputs(str2);
	printf("%d\n", mystrspn(str1, str2));
}
void mystrstrTest()
{
	char str1[] = "10001001101al;sdkfj\x1";
	char str2[] = "101\x1";
	myputs("Mystrstr test\nstr1, str2 and function result:\x1");
	myputs(str1);
	myputs(str2);
	myputs(mystrstr(str1, str2));
}
void mystrtokTest()
{
	char str[] = "- This, a sample string.\x1";
	char * pch;
	myputs("Mystrtok test\nstring and its tokens:\x1");
	myputs(str);
	pch = mystrtok(str, " ,.-\x1");
	while (pch != NULL)
	{
		myputs(pch);
		pch = mystrtok(NULL, " ,.-\x1");
	}
}
//other functions tests
void mymemsetTest()
{
	char str[] = "almost every programmer should know memset!\x1";
	myputs("Mymemset test\nstring before and after replacing characters with '-':\x1");
	myputs(str);
	mymemset(str, '-', 6);
	myputs(str);
	return 0;
}
void mystrlenTest()
{
	char str[] = "123456789\x1";
	myputs("Mystrlen test \nstring and its length: \x1");
	myputs(str);
	printf("%d\n", mystrlen(str));
}

int main()
{
	_getch();
}
