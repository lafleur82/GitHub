
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>


/***********************************************

Write a program that implements the following:
feof()
perror()
Return errno
strerror()

Replicate some error to test your implementation
Read a non-existent file
Write to a locked file
Misuse a math function

*************************************************/

int main()
{
	int errorNumber = 0;
	char readFromFile = 0;

	FILE * myFile_ptr = fopen("test.txt", "r");	

	if (!myFile_ptr)
	{
		perror("Error: ");
	}
	else
	{
		while (!feof(myFile_ptr))
		{
			readFromFile = getc(myFile_ptr, stdout);
			putchar(readFromFile);
		}

		fclose(myFile_ptr);
		printf("\n");
	}

	getchar();
	return 0;
}