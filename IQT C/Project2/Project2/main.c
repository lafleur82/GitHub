#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "MyStringHeader.h"

int main()
{
	char myString[] = "This is a string";

	reverse_it(myString, sizeof(myString)/sizeof(myString[0]));
	print_the_count(myString, sizeof(myString) / sizeof(myString[0]));

	getchar();

	return 0;
}