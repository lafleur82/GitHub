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

		switch (letter)
		{
		case 'A':
			letters[0] += 1;
			break;
		case 'B':
			letters[1] += 1;
			break;
		case 'C':
			letters[2] += 1;
			break;
		case 'D':
			letters[3] += 1;
			break;
		case 'E':
			letters[4] += 1;
			break;
		case 'F':
			letters[5] += 1;
			break;
		case 'G':
			letters[6] += 1;
			break;
		case 'H':
			letters[7] += 1;
			break;
		case 'I':
			letters[8] += 1;
			break;
		case 'J':
			letters[9] += 1;
			break;
		case 'K':
			letters[10] += 1;
			break;
		case 'L':
			letters[11] += 1;
			break;
		case 'M':
			letters[12] += 1;
			break;
		case 'N':
			letters[13] += 1;
			break;
		case 'O':
			letters[14] += 1;
			break;
		case 'P':
			letters[15] += 1;
			break;
		case 'Q':
			letters[16] += 1;
			break;
		case 'R':
			letters[17] += 1;
			break;
		case 'S':
			letters[18] += 1;
			break;
		case 'T':
			letters[19] += 1;
			break;
		case 'U':
			letters[20] += 1;
			break;
		case 'V':
			letters[21] += 1;
			break;
		case 'W':
			letters[22] += 1;
			break;
		case 'X':
			letters[23] += 1;
			break;
		case 'Y':
			letters[24] += 1;
			break;
		case 'Z':
			letters[25] += 1;
			break;
		default:
			break;
		} //end switch

	} while (letter != '\n');

	for (int i = 0; i < 26; i++)
	{
		printf("%c:\t%d\n", i+65, letters[i]);
	}

	return 0;
}