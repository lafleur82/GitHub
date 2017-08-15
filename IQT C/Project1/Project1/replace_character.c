//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// PERFORMANCE LAB I.3.A-1 //////////////////////////////
////////////////////////////////// "Healthy Substiutions" ////////////////////////////////
///////////////////////////////////// Student Stub Code //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// Do not modify main()
// Write the code body for the following function prototype:
//     int replace_character (char * string, const char findThisChar, const char replaceItWithThis);
// This function takes the following parameters:
//     A pointer to a null-terminated string as a parameter (string)
//     A constant character to find in the afore mentioned string (findThisChar)
//     A constant character to replace the afore mentioned 'search' character (replaceItWithThis)
// This function must replace all occurences of "findThisChar" with "replaceItWithThis"
// The return value should represent the number of characters that were changed
//     with the following exceptions:
//         Return ERR_NONE_FOUND if no newlines are found
//         Return ERR_NULL_POINTER if the pointer to the string (string) is NULL
//         Return ERR_FIND_EQUALS_REPLACE if "findThisChar" is equal to "replaceItWithThis"
//         Return ERR_NON_PRINTABLE_CHARACTER if "findThisChar" or "replaceItWithThis"
//             is a non-printable character
// Do not process a NULL string pointer (string)
//////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

/* 
 * This pre-processing directive determines whether the program will
 *     run unit tests and/or prompt the user for input depending on
 *     what #define statements are uncommented.
 * #define AUTO // Runs unit test
 * #define MANUAL // Asks user for input
 * Uncomment out both #defines to first execute unit testing and then take user input
 */
#define AUTO
//#define MANUAL

#define NUMBER_OF_TESTS 12 // There are currently 12 unit tests.  More may be added by increasing this value and adding more cases.
#define ERR_NONE_FOUND 0 // Return value if no occurences of "findThisChar" are found
#define ERR_NULL_POINTER -1 // Return value if string is NULL
#define ERR_FIND_EQUALS_REPLACE -2 // Return value if "findThisChar" is the same as "replaceItWithThis"
#define ERR_NON_PRINTABLE_CHARACTER -3 // Return value if "findThisChar" or "replaceItWithThis" are non-printable characters

void clear_input_stream();
int replace_character(char * string, const char findThisChar, const char replaceItWithThis);

int main(void)
{
	/* VARIABLE INITIALIZATION */
	int i = 0; // Iterating variable
	char findChar = 0; // Local variable to store the search character
	char replaceChar = 0; // Local variable to store the replacement character

	/* The AUTO code block allows runs established unit tests to give students formal, standardized feedback on their code. */
#ifdef AUTO
	char testString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };
	const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };
	int tempResult = 999; // Temporarily holds the return value of replace_character to compare it to expected 'static' value per unit test
	int numberOfErrors = 0; // Counts the total number of FAILed unit tests
	printf("PERFORMING TESTING\n");

	for (i = 1; i <= NUMBER_OF_TESTS; i++)
	{
		strncpy(testString, originalTestString, strlen(testString)); // Resets testString by copying original version into it
		switch (i) // Cases represent the various unit tests.  Numbers equate to test arrays.
		{
			case (1):
				printf("\nTest #1 - Make one lowercase letter replacement\n");
				findChar = 'a';
				replaceChar = 'b';
				char test1[] = { "testSTRING-bbcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };
//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(testString, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (1 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				tempResult = strcmp(testString, test1);
				printf("\tReplacement:\t");
				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
				break;

			case (2) :
				printf("\nTest #2 - Make one uppercase letter replacement\n");
				findChar = 'X';
				replaceChar = 'Y';
				char test2[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWYYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };
//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(testString, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (1 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				tempResult = strcmp(testString, test2);
				printf("\tReplacement:\t");
				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
				break;

			case (3) :
				printf("\nTest #3 - Make two lowercase letter replacements\n");
				findChar = 's';
				replaceChar = 'n';
				char test3[] = { "tentSTRING-abcdefghijklmnopqrntuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };
//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(testString, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (2 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				tempResult = strcmp(testString, test3);
				printf("\tReplacement:\t");
				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
				break;

			case (4) :
				printf("\nTest #4 - Make two uppercase letter replacements\n");
				findChar = 'T';
				replaceChar = 'P';
				char test4[] = { "testSPRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSPUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };
//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(testString, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (2 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				tempResult = strcmp(testString, test4);
				printf("\tReplacement:\t");
				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
				break;

			case (5) :
				printf("\nTest #5 - Make one non-alphabet replacement\n");
				findChar = '[';
				replaceChar = '{';
				char test5[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-={]',./!@#$%^&*()_+{}:<>?\n" };
//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(testString, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (1 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				tempResult = strcmp(testString, test5);
				printf("\tReplacement:\t");
				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
				break;

			case (6) :
				printf("\nTest #6 - Make two non-alphabet replacements\n");
				findChar = '-';
				replaceChar = '_';
				char test6[] = { "testSTRING_abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890_=[]',./!@#$%^&*()_+{}:<>?\n" };
				//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(testString, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (2 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				tempResult = strcmp(testString, test6);
				printf("\tReplacement:\t");
				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
				break;

			case (7) :
				printf("\nTest #7 - Testing a NULL pointer\n");
				findChar = '-';
				replaceChar = '_';
				char * test7 = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };
//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(NULL, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (ERR_NULL_POINTER == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				//tempResult = strcmp(testString, test7); // test7 is NULL
				printf("\tReplacement:\tNot executed.\n");
/*				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
*/
				break;

			case (8) :
				printf("\nTest #8 - Search character matches replace character\n");
				findChar = '-';
				replaceChar = '-';
				char test8[] = { "testSTRING_abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890_=[]',./!@#$%^&*()_+{}:<>?\n" };
//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(testString, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (ERR_FIND_EQUALS_REPLACE == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				tempResult = strcmp(testString, test8);
				printf("\tReplacement:\tNot tested.\n");
/*				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
*/
				break;

			case (9) :
				printf("\nTest #9 - Search character not found\n");
				findChar = '\\';
				replaceChar = 'n';
				char test9[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };
//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(testString, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (ERR_NONE_FOUND == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				tempResult = strcmp(testString, test9);
				printf("\tReplacement:\t");
				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
				break;

			case (10) :
				printf("\nTest #10 - Search for a non-printable character\n");
				findChar = 10;
				replaceChar = 'n';
				char test10[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };
//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(testString, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (ERR_NON_PRINTABLE_CHARACTER == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				tempResult = strcmp(testString, test10);
				printf("\tReplacement:\t");
				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
				break;

			case (11) :
				printf("\nTest #11 - Replace a non-printable character\n");
				findChar = 't';
				replaceChar = 11;
				char test11[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };
//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(testString, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (ERR_NON_PRINTABLE_CHARACTER == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				tempResult = strcmp(testString, test11);
				printf("\tReplacement:\t");
				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
				break;

			case (12) :
				printf("\nTest #12 - Replace a non-printable character with\nanother non-printable character\n");
				findChar = 10;
				replaceChar = 12;
				char test12[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };
//				const char originalTestString[] = { "testSTRING-abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZI.3.567890-=[]',./!@#$%^&*()_+{}:<>?\n" };

				/* TESTING */
				/* Return Value Testing */
				tempResult = replace_character(testString, findChar, replaceChar);
				printf("\tReturn Value:\t");
				if (ERR_NON_PRINTABLE_CHARACTER == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}

				/* Algorithm Testing */
				tempResult = strcmp(testString, test12);
				printf("\tReplacement:\t");
				if (0 == tempResult)
				{
					printf("PASS\n");
				}
				else
				{
					printf("FAIL\n");
					numberOfErrors++;
				}
				break;

			default:
				printf("You tried to run %d tests but there aren't %d of tests yet. \n", i, NUMBER_OF_TESTS);
				break;
		}
	}
	if (1 == numberOfErrors)
	{
		printf("You had %d error\n", numberOfErrors);
	}
	else
	{
		printf("You had %d errors\n", numberOfErrors);
	}
	
#endif

	/* The MANUAL code block allows students to manually interact with their functions. */
#ifdef MANUAL
	char badString1[] = { "Off we go into the wild blue vonder..." }; // One error
	char badString2[] = { "I speqqed something wrong in this sentence." }; // Two errors
	char badString3[] = { "Zwo strings walk into a bar.\nZhe first string says, \"I'll have a beer.#MV*()>SDk+!^&@P&]JEA&#65535\"\nZhe second string says, \"Sorry.  He's not null-terminated.\"\n" }; // Three errors
	char badString4[] = { "How much Food could a Foodchuck chuck if a woodchuck could chuck Food?" }; // Some errors
	char badString5[] = { "What do you do if there's nothing wrong with a sentence?" }; // No errors
	char * badString6 = NULL;
	char * badStringArray[] = { badString1, badString2, badString3, badString4, badString5, badString6 };
	int functionResult = 999;
	size_t numberOfManualStrings = sizeof(badStringArray) / sizeof(*badStringArray); // Stores the number of strings in the badArray string array

	for (i = 0; i < numberOfManualStrings; i++)
	{
		printf("\nString #%d (of %d):\n%s\n", i + 1, numberOfManualStrings, badStringArray[i]); // Preface each manual string
		printf("What character do you want to replace?  "); // Prompt for findThisChar
		findChar = getchar(); 
		clear_input_stream();
		printf("What character do you want to replace it with?  "); // Prompt for replaceItWithThis
		replaceChar = getchar(); 
		clear_input_stream();
		functionResult = replace_character(badStringArray[i], findChar, replaceChar); // Runs replace_character() and stores the result
		printf("String #%d is now:\n%s\n", i + 1, badStringArray[i]); // Prints the modified string
		printf("Your function returned %d \n", functionResult); // Shows student the return value of replace_character()
	}
#endif

	return 0;
}

void clear_input_stream()
{
	int c; 
	while((c = getchar()) != '\n' && c != EOF);
}

/*
* FUNCTION:   int replace_character(char * string, const char findThisChar, const char replaceItWithThis)
*
* ARGUMENTS:  string is a pointer to a null-terminated string.  The string is passed by reference and modified in place.
*             findThisChar is the character to 'search' for
*             replaceItWithThis is the character to 'replace' the 'search' character with
*
* RETURNS:	  Number of characters that were replaced
*             ERR_NONE_FOUND if no occurrences of "findThisChar" are found
*             ERR_NULL_POINTER if string == NULL
*             ERR_FIND_EQUALS_REPLACE if "findThisChar" is equal to "replaceItWithThis"
*             ERR_NON_PRINTABLE_CHARACTER if "findThisChar" or "replaceItWithThis" are non-printable characters
*
* NOTES:      This function replaces all occurrences of "findThisChar" with "replaceItWithThis" in "string"
*/
int replace_character(char * string, const char findThisChar, const char replaceItWithThis)
{
	int count = 0;

	if (string)
	{
		if (findThisChar == replaceItWithThis)
		{
			return ERR_FIND_EQUALS_REPLACE;
		}
		else if (!(findThisChar > 31 && findThisChar < 127) || !(replaceItWithThis > 31 && findThisChar < 127))
		{
			return ERR_NON_PRINTABLE_CHARACTER;
		}
		else
		{
			for (int i = 0; i < strlen(string); i++)
			{
				if (string[i] == findThisChar)
				{
					string[i] = replaceItWithThis;
					count++;
				}
			}
			if (count < 1)
			{
				return ERR_NONE_FOUND;
			}
			else
			{
				return count;
			}
		}
	}
	else
	{
		return ERR_NULL_POINTER;
	}
}
