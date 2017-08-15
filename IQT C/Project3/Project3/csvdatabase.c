#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


/*
Open a new file in write mode
Choose three separate data types to store as ‘tuples’ in a comma separated value (CSV) database                           
(e.g., int, string, and float as studentID, username, GPA)
Take human-readable input from the user and translate that into CSV-formatted entries in the file
*/


int main()
{
	FILE * newFile_ptr = fopen("CSV_Database_1.txt", "w");
	int age = 0;
	char string[25] = { 0 };
	float temp = 0.0;

	printf("Enter your age:\n");
	fscanf(stdin, "%d", &age);
	printf("\n");

	printf("Enter your phone number:\n(i.e. (210) 555-1234)\n");
	fscanf(stdin, "%25s", string);
	printf("\n");

	printf("Enter the current temperature:\n(i.e. 85.4)\n");
	fscanf(stdin, "%f", &temp);
	printf("\n");

	//output to file
	if (age && string && temp)
	{
		fprintf(newFile_ptr, "%d,%s,%.1f\n", age, string, temp);
	}
	fclose(newFile_ptr);

	return 0;
}