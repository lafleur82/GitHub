#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//variables
	int letters[26] = { 0 };
	char letter = 0;

	printf("Enter a sentence to count the letters: \n");

	do
	{
		letter = toupper(getchar());
		if (letter >= 65 || letter <= 90)
		{
			letters[letter - 65] += 1;
		}

	} while (letter != '\n');

	for (int i = 0; i < 26; i++)
	{
		if (letters[i])
		{
			printf("%c:\t%d\n", i + 65, letters[i]);
		}
	}

	return 0;
}