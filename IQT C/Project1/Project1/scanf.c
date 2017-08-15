#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char fname[26] = { 0 };
	char mname[26] = { 0 };
	char lname[26] = { 0 };

	printf("Enter your first, middle, and last name. \n");
	printf("(Tab delimited, max 25 characters per name): \n");
	_flushall();
	scanf("%25[A-Za-z ]\t%25[A-Za-z ]\t%25[A-Za-z ]", fname, mname, lname);
	printf("%s\t\n%s\t\n%s\n", fname, mname, lname);
}