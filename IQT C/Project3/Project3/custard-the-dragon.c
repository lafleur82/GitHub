#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define length 14
#define width 60


/*
Save Ogden Nash’s poem “The Tale of Custard The Dragon” into a text file
Zeroize a two-dimensional char array which can hold the first 14 rows of the poem, 60 characters per row
Write a C program to:
Open the file in read-only mode
Read it line-by-line
Store each line separately in the two-dimensional array
Close the file after reading 14 rows
Print the two-dimensional array
*/


int main()
{
	int errorNumber = 0;
	FILE * myFile_ptr = fopen("test", "r");
	
	errorNumber = errno;

	if (!myFile_ptr)
	{
		perror(strerror(errorNumber));
	}

	getchar();
	return 0;
}