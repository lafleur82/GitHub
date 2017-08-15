#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
Open an existing file in read mode
Open a new file in write mode
Copy the existing file into the new file char-by-char
Close the existing file
Close and open the new file in read mode
Print the new file char-by-char  
*/


int main()
{
	//declare streams for old file and new file
	FILE * readFile_ptr = fopen("custard-the-dragon.txt", "r");
	FILE * writeFile_ptr = fopen("newfile.txt", "w");
	int readFromFile = 0;

	//read the old file into the new file
	if (readFile_ptr && writeFile_ptr)
	{
		while ((readFromFile = getc(readFile_ptr)) != EOF)
		{
			fputc(readFromFile, writeFile_ptr);
		}
		//close the file streams
		fclose(readFile_ptr);
		fclose(writeFile_ptr);
	}
	else
	{
		printf("Couldn't read file.");
	}

	//open read stream to new file
	FILE * readNewFile_ptr = fopen("newfile.txt", "r");

	//read the new file to stdout
	if (readNewFile_ptr)
	{
		while ((readFromFile = (getc(readNewFile_ptr))) != EOF)
		{
			putc(readFromFile, stdout);
		}
		fclose(readNewFile_ptr);
	}
	else
	{
		printf("Couldn't read file.");
	}

	getchar();
	return 0;
}