//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// PERFORMANCE LAB I.3.A-2 //////////////////////////////
////////////////////////////////////// "Alphabet Soup" ///////////////////////////////////
///////////////////////////////////// Student Stub Code //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// WARNING:  Do not modify main()
// PURPOSE:
//     Take input (e.g., stdin) and count the alphabet letters from the input
//     Stop taking input on Ctrl-D (char breakCharacter = 17;)
//     Each function utilizes a global array (see: alphabetCount[])
//     Each function's return values will provide integrity checks
// REASON:
//     main() should not change
//     main() requires given execution and specific return values
//     The only modification outside of main() should be the function definitions
//         and commenting/uncommenting the various unit test macros
//     Programmers often must code within previously established frameworks
// TESTING:
//     main() includes built-in testing
//     The type of test(s) to be run are determined by the #define lines
//     Each function has its own test
//     The overall program has its own test
//     There is also a manual input test to aid the student by providing interaction
//     The Structured_Input.txt file must be in C:\Temp
//     temp.txt is another file utilized in C:\Temp but main() will create the file
//         if temp.txt isn't already there.  It is merely for temporary use.
// GLOBAL ARRAY:
//     Initialized outside main()
//     Accessed directly by all of the program's functions
//     Dimension fo 26 (one index per alphabet letter)
//     Value in each index contains the current count of that letter
//     0 represents A, 1 represents B, 2 represents C, etc.
//     The count for "a" (and "A" since the count is case-insensitive) is stored in
//         alphabetCount[0].  The rest of the letters follow the index numbers
//         in alphabetic order.
// NOTE:
//     The overall structure of this program is complicated.  The student is not
//         required to see the forest (the entire program) while programming a 
//         tree (one function).  If the students follow the given criteria for
//         each of the functions, all should be well.  The unit tests are built
//         for iterative testing.  This means they can define a single function
//         and then run tests on that function by itself (by commenting out all
//         of the other tests, of course)
//////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>


/*
* This pre-processing directive determines whether the program will
*     run unit tests and/or prompt the user for input depending on
*     what #define statements are uncommented.
#define AUTO_COUNT_INPUT // Runs unit tests on int count_input(FILE * inputStream)
#define AUTO_CLEAR_ARRAY // Runs unit tests on clear_global_array(int currentAlphaCount)
#define AUTO_PRINT_COUNT // Runs unit tests on print_alphabet_count(int printTheCount)
#define AUTO_FULL_PROGRAM // Runs unit tests on the entire program as a whole, incorporating all functions
#define MANUAL // Allows the programmer to manually provide input to test the response of the program as a whole
* Uncomment out multiple #defines to multiple tests in a single run
*/
#define AUTO_COUNT_INPUT
#define AUTO_CLEAR_ARRAY
#define AUTO_PRINT_COUNT
#define AUTO_FULL_PROGRAM
//#define MANUAL

#define ERR_NULL_POINTER -1 // Return value if string is NULL
#define ERR_COUNT_MISMATCH -2 // Return value if the alphabet letter count doesn't equal the global array
#define SMALL_TEST_FILE_LOCATION "C:\\Temp\\temp.txt" // Used for individual unit tests
#define LARGE_TEST_FILE_LOCATION "C:\\Temp\\Structured_Input.txt" // Used for full unit test

int alphabetCount[26] = { 0 }; // Global array that holds the current count of alphabet letters

int count_input(FILE * inputStream); // Returns character input and updates alphabetCount[] with number of letters
int clear_global_array(int currentAlphaCount); // Returns a boolean result of currentAlphaCount compared to what was found in alphabetCount[]; Empties alphabetCount[]
int print_alphabet_count(int printTheCount); // Returns sum of all values in alphabetCount[]; printTheCount is a boolean argument to print alphabetCount[] results to stdout


int main(void)
{
	long int totalChars = 0; // Holds the total number of characters, letters or otherwise, that have been counted
	long int totalAlphaChars = 0; // Holds the total number of alphabet letters that have been counted
	int i = 0; // Incrementing variable
	int j = 0; // Incrememnting variable
	int numUnitTestsRun = 0; // Holds the number of unit tests that have been run
	int numUnitTestsPassed = 0; // Holds the number of unit tests that have passed

	/*
	* This unit test will send sample input into your count_input() function
	* It passes this input by utilizing crafted char arrays (e.g, testString1, testString2)
	* Each char array is coupled with a similarly numbered parallel int array (e.g., testAlphabetCount1, testAlphabetCount2)
	*     which represents the expected status of the global alphabetCount[] array when the count is complete.
	* The expected return value for each char array is stored in a parallet int array (autoCountInputStringAnswers)
	* The char arrays are stored in a char * array (autoCountInputStringArray)
	* The parallel int arrays are stored in an int * array (testAlphabetCount)
	* The char arrays are printed to a FILE * (autoCountInputTestFile) to be passed as a parameter to count_input()
	* Not only is the return value for each function call verified, the post-function status of the global array
	*     is also verified against the parallel int array.
	*/
#ifdef AUTO_COUNT_INPUT
#define TEST_BUFF_SIZE 512 // Standardized buffer size to aid in looping

	/* Define Test 1 */
	char testString1[TEST_BUFF_SIZE] = { "a B c D?" }; // Appropriately sized string properly marked
	testString1[8] = 17;
	testString1[9] = 0;
	int testAlphabetCount1[26] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	/* Define Test 2 */
	char testString2[TEST_BUFF_SIZE] = { "1 @ 3 $ thumb War!" }; // Large string with empty space improperly marked
	testString2[TEST_BUFF_SIZE - 2] = 17;
	testString2[TEST_BUFF_SIZE - 1] = 0;
	int testAlphabetCount2[26] = { 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0 };

	/* Define Test 3*/
	char testString3[TEST_BUFF_SIZE] = { "32 Non-printable characters" }; // String that contains non-printable characters, empty space, and is improperly marked

	for (i = 31; i >= 0; i--)
	{
		if (17 == i)
		{
			continue; // Skip char 17 since we don't want to end prematurely
		}
		testString3[TEST_BUFF_SIZE - i - 3] = i;
	}

	testString3[TEST_BUFF_SIZE - 2] = 17;
	testString3[TEST_BUFF_SIZE - 1] = 0;
	int testAlphabetCount3[26] = { 3, 1, 2, 0, 2, 0, 0, 1, 1, 0, 0, 1, 0, 3, 1, 1, 0, 3, 1, 2, 0, 0, 0, 0, 0, 0 };

	/* Define Test 4 */
	char testString4[TEST_BUFF_SIZE] = { "Properly marked non-printable characters: " }; // String that contains non-printable characters and no empty space

	for (i = 43; i < (43 + 18); i++)
	{
		testString4[i] = i - 42;
	}
	int testAlphabetCount4[26] = { 4, 1, 2, 1, 4, 0, 0, 1, 1, 0, 1, 2, 1, 3, 2, 3, 0, 6, 1, 2, 0, 0, 0, 0, 1, 0 };

	/* Define Parallel Arrays */
	char * autoCountInputStringArray[] = { testString1, testString2, testString3, testString4 };
	int autoCountInputStringAnswers[] = { 9, 511, 483, 60 };
	int * testAlphabetCount[] = { testAlphabetCount1, testAlphabetCount2, testAlphabetCount3, testAlphabetCount4 };

	FILE * autoCountInputTestFile = NULL; // File pointer
	autoCountInputTestFile = fopen(SMALL_TEST_FILE_LOCATION, "w+");

	if (autoCountInputTestFile) // Verify file pointer is not NULL
	{
		printf("\n***********************************\n");
		printf("RUNNING UNIT TESTS ON count_input()\n");
		printf("***********************************\n\n");
		for (i = 0; i < sizeof(autoCountInputStringArray) / sizeof(autoCountInputStringArray[0]); i++)
		{
			//			fputs(autoCountInputStringArray[i], autoCountInputTestFile); // Isn't copying all characters because it's stopping at NULL instead of continuing to Ctrl-Q
			for (j = 0; j < TEST_BUFF_SIZE; j++)
			{
				fputc(autoCountInputStringArray[i][j], autoCountInputTestFile); // Places the current testString into the test file character by character
			}

			/* AUTO_COUNT_INPUT Unit Test Execution 1 - 4 */
			printf("Test %d:\n\t", i + 1);
			printf("Return Value\t");
			numUnitTestsRun++;
			if (autoCountInputStringAnswers[i] == count_input(autoCountInputTestFile))
			{
				printf("PASS\n");
				numUnitTestsPassed++;
			}
			else
			{
				printf("FAIL\n");
				printf("\tThe unit test was expecting %d \n", autoCountInputStringAnswers[i]);
			}
			printf("\tGlobal Array\t");
			numUnitTestsRun++;
			int failedCheck = 0;
			for (j = 0; j < 26; j++)
			{
				if (testAlphabetCount[i][j] != alphabetCount[j])
				{
					printf("FAIL\n");
					failedCheck = 1;
					break;
				}
			}
			if (!failedCheck)
			{
				printf("PASS\n");
				numUnitTestsPassed++;
			}
			memset(alphabetCount, 0, 26 * sizeof(int));
			freopen(SMALL_TEST_FILE_LOCATION, "w+", autoCountInputTestFile); // Reopen the file, emptying it
			if (!autoCountInputTestFile)
			{
				printf("Error reopening file.\n");
				break;
			}
		}
		/* AUTO_COUNT_INPUT Unit Test Execution 5 */
		printf("Test 5:\n\tReturn Value\t"); // Manual unit test to verify response to NULL pointer input
		numUnitTestsRun++;
		if (ERR_NULL_POINTER == count_input(NULL))
		{
			printf("PASS\n");
			numUnitTestsPassed++;
		}
		else
		{
			printf("FAIL\n");
			printf("\tFunction did not return the proper value for a NULL pointer.\n");
		}
		printf("\tGlobal Array\t");
		numUnitTestsRun++;
		int failedCheck = 0;
		for (j = 0; j < 26; j++)
		{
			if (alphabetCount[j])
			{
				printf("FAIL\n");
				failedCheck = 1;
				break;
			}
		}
		if (!failedCheck)
		{
			printf("PASS\n");
			numUnitTestsPassed++;
		}
		if (autoCountInputTestFile)
		{
			fclose(autoCountInputTestFile);
		}
	}

#endif

	/*
	* This unit test will call your clear_global_array() function to clear different values in the alphabetCount global array
	* It sets non-zero values to the alphabetCount global array and calls the clear_global_array() function to clear it
	* These tests are able to compare pre-determined results to the function's return value and performance
	* For each test, it tests the function's return value first
	* Then it verifies that all of alphabetCount[]'s elements have been set to zero (0)
	* A properly functioning clear_global_array() is a pre-requisite to passing all of the print_alphabet_count()
	*     unit tests since print_alphabet_count() is required to call clear_global_array().
	*/
#ifdef AUTO_CLEAR_ARRAY

	printf("\n******************************************\n");
	printf("RUNNING UNIT TESTS ON clear_global_array()\n");
	printf("******************************************\n\n");

	for (i = 1; i <= 5; i++)
	{
		printf("Test %d: \n\t", i);

		for (j = 0; j < 26; j++)
		{
			alphabetCount[j] = i;
		}

		printf("Return Value\t");
		numUnitTestsRun++;

		if (clear_global_array(i * 26))
		{
			printf("PASS\n");
			numUnitTestsPassed++;
		}
		else
		{
			printf("FAIL\n");
		}

		printf("\tReset Array\t");
		numUnitTestsRun++;

		int failedCheck = 0; // Boolean variable used to determine if alphabetCount failed its verification check
		for (j = 0; j < 26; j++)
		{
			if (alphabetCount[j])
			{
				failedCheck = 1;
				memset(alphabetCount, 0, 26 * sizeof(int));
				break;
			}
		}
		if (failedCheck)
		{
			printf("FAIL\n");
		}
		else
		{
			printf("PASS\n");
			numUnitTestsPassed++;
		}
	}

#endif

	/*
	* This unit test will make adjustments to the alphabetCount[] global array and test print_alphabet_count()'s
	*     ability to invoke clear_global_array() to zeroize the values stored within alphabetCount[]
	* It sets non-zero values to the alphabetCount global array and verifies print_alphabet_count()'s ability
	*     to return the sum of all the values.
	* Then it verifies that all of alphabetCount[]'s elements have been set to zero (0)
	* A properly functioning clear_global_array() is a pre-requisite to passing all of the print_alphabet_count()
	*     unit tests since print_alphabet_count() is required to call clear_global_array().
	* These unit tests are very similar to the clear_global_array() unit tests.
	*/
#ifdef AUTO_PRINT_COUNT

	printf("\n********************************************\n");
	printf("RUNNING UNIT TESTS ON print_alphabet_count()\n");
	printf("********************************************\n\n");

	for (i = 1; i <= 5; i++)
	{
		printf("Test %d: \n\t", i);

		for (j = 0; j < 26; j++)
		{
			alphabetCount[j] = i;
		}

		printf("Return Value\t");
		numUnitTestsRun++;

		if (print_alphabet_count(0) == (i * 26))
		{
			printf("PASS\n");
			numUnitTestsPassed++;
		}
		else
		{
			printf("FAIL\n");
		}

		printf("\tReset Array\t");
		numUnitTestsRun++;

		int failedCheck = 0; // Boolean variable used to determine if alphabetCount failed its verification check
		for (j = 0; j < 26; j++)
		{
			if (alphabetCount[j])
			{
				failedCheck = 1;
				memset(alphabetCount, 0, 26 * sizeof(int));
				break;
			}
		}
		if (failedCheck)
		{
			printf("FAIL\n");
		}
		else
		{
			printf("PASS\n");
			numUnitTestsPassed++;
		}
	}
	memset(alphabetCount, 0, 26 * sizeof(int));
	printf("Test 6: Empty array\n\tReturn Value\t");
	numUnitTestsRun++;
	if (0 == print_alphabet_count(0))
	{
		printf("PASS\n");
		numUnitTestsPassed++;
	}
	else
	{
		printf("FAIL\n");
	}


#endif


	/* This unit test will test the entire program at once. It accomplishes by using a pre-written
	*     that will need to be staged in LARGE_TEST_FILE_LOCATION as #defined at the beginning.
	* This unit test should be able to detect and resolve any changes that have been made to the existing
	*     file.  This should alleviate any concerns as to the integrity of the unit test since it is
	*     using an external file to pass test data to this program.
	*/
#ifdef AUTO_FULL_PROGRAM

#define BUFF_SIZE 512
	FILE * preStagedInput = NULL; // File pointer
	preStagedInput = fopen(LARGE_TEST_FILE_LOCATION, "r"); // Open the file that contains the test input for read-only
	if (preStagedInput) // Verify the file opened
	{
		printf("\n************************************\n");
		printf("RUNNING UNIT TESTS ON THE ENTIRE LAB\n");
		printf("************************************\n\n");
		printf("CHECKING FILE INTEGRITY\n\t");
		char copyBuffer[BUFF_SIZE] = { 0 }; // Holds the information that will be read from the test input file
		/* Holds original copy of what the test input file should look like */
		char verificationBuffer[BUFF_SIZE] = { "This file was created to aid a unit test for Performance Lab I.3.a-2, Variable Scope \"Alphabet Soup\".\n\nThe print function should give this output:\n\nYou've input a total of 364 characters.\nA: 18\nB: 4\nC: 7\nD: 4\nE: 17\nF: 7\nG: 2\nH: 7\nI: 12\nJ: 1\nK: 1\nL: 9\nM: 2\nN: 8\nO: 15\nP: 9\nQ: 1\nR: 10\nS: 10\nT: 23\nU: 11\nV: 5\nW: 2\nX: 2\nY: 3\nZ: 1\nYou've input a total of 191 letters.\n" };
		verificationBuffer[363] = 17; // Manually set the 'escape character' (Ctrl-Q) since I can't type it
		char tempChar = 0;

		/* Copy the contents of the file into copyBuffer[] */
		i = 0; // Incrementing variable is zeroized because it is used elsewhere
		while (tempChar != 17) // Stop copying when you reach decimal value 17 (Ctrl-Q)
		{
			tempChar = getc(preStagedInput); // Read one character from the test input file
			copyBuffer[i] = tempChar; // Put that character into the copyBuffer
			i++; // Advance to the next element
			if ((BUFF_SIZE - 1) == i) // Reached the end of the copy buffer
			{
				copyBuffer[i] = 0; // Manually ensure string is null terminated... for safety
				break; // Will cause the while loop to end
			}
		}
		copyBuffer[BUFF_SIZE - 1] = 0; // Manually null terminate the string... for safety
		verificationBuffer[BUFF_SIZE - 1] = 0; // Manually null terminate the string... for safety

		if (!(strcmp(copyBuffer, verificationBuffer))) // strcmp() will compare two strings
		{
			printf("The file has not been changed.\n");
		}
		else // ...test input file and original copy are not identical!
		{
			printf("We have a problem!\n\tThe file appears to have been changed.\n\tFixing file...\n");
			rewind(preStagedInput); // Rewinds the file pointer to the beginning of the file
			freopen(LARGE_TEST_FILE_LOCATION, "w", preStagedInput); // Closes and reopens the file in write mode
			if (preStagedInput) // Verifies the reopen functioned on the file pointer
			{
				for (i = 0; i < BUFF_SIZE; i++) // Iterates through original copy
				{
					if (0 == verificationBuffer[i]) // Stops writing to the file when it encounters a null character from the original copy
					{
						break;
					}
					putc(verificationBuffer[i], preStagedInput); // Places the original version of the file into the test input file character by character
				}
				rewind(preStagedInput); // Rewinds the file pointer
				freopen(LARGE_TEST_FILE_LOCATION, "r", preStagedInput); // Reopens the test input file in read-only mode... again
			}

			if (preStagedInput) // Verifies the read-only reopen was successful
			{
				printf("\tThe file contents have been replaced.\n");
			}
			else // ...otherwise something went wrong
			{
				printf("\tReopening the file to fix the contents did not work.\n");
				return -1;
			}
		}

		/* Full Test #1 */
		printf("TEST 1\tCounting total characters:  \n\t");
		totalChars = count_input(preStagedInput);
		printf("Return Value\t");
		numUnitTestsRun++;
		if (364 == totalChars)
		{
			printf("PASS\n");
			numUnitTestsPassed++;
		}
		else
		{
			printf("FAIL\n");
		}
		printf("\tGlobal Array\t");
		numUnitTestsRun++;
		int testAlphabetCountFull[26] = { 18, 4, 7, 4, 17, 7, 2, 7, 12, 1, 1, 9, 2, 8, 15, 9, 1, 10, 10, 23, 11, 5, 2, 2, 3, 1 };
		int failedCheck = 0; // Boolean variable used to determine if alphabetCount failed its verification check
		for (j = 0; j < 26; j++)
		{
			if (alphabetCount[j] != testAlphabetCountFull[j])
			{
				failedCheck = 1;
				memset(alphabetCount, 0, 26 * sizeof(int));
				break;
			}
		}
		if (failedCheck)
		{
			printf("FAIL\n");
		}
		else
		{
			printf("PASS\n");
			numUnitTestsPassed++;
		}

		/* Full Test #2 */
		totalAlphaChars = print_alphabet_count(0);
		printf("TEST 2\tCounting alphabet letters:  \n\t");
		printf("Return Value\t");
		numUnitTestsRun++;
		if (191 == totalAlphaChars)
		{
			printf("PASS\n");
			numUnitTestsPassed++;
		}
		else
		{
			printf("FAIL\n");
		}

		printf("\tGlobal Array\t");
		numUnitTestsRun++;
		failedCheck = 0; // Reseting boolean variable used to determine if alphabetCount failed its verification check
		for (j = 0; j < 26; j++)
		{
			if (alphabetCount[j])
			{
				failedCheck = 1;
				memset(alphabetCount, 0, 26 * sizeof(int));
				break;
			}
		}
		if (failedCheck)
		{
			printf("FAIL\n");
		}
		else
		{
			printf("PASS\n");
			numUnitTestsPassed++;
		}
	}
	else
	{
		printf("\n\nThere has been an error opening the test input file\n");
	}

	if (preStagedInput)
	{
		fclose(preStagedInput);
	}
#endif


#ifdef MANUAL
	printf("This program will count the number of characters and letters you input.\nWhen you are done with your input, input Ctrl-Q and press Enter.\n\n");
	totalChars = count_input(stdin);
	_flushall();
	printf("You've input a total of %d characters.\n", totalChars);
	totalAlphaChars = print_alphabet_count(1);
	printf("You've input a total of %d letters.\n", totalAlphaChars);
#endif

	if (numUnitTestsRun)
	{
		printf("\n\nYou've run %d unit tests and passed %d of them. \n", numUnitTestsRun, numUnitTestsPassed);
	}
	return 0;
}

/*
* FUNCTION:   int count_input(FILE * inputStream)
*
* ARGUMENTS:  inputStream is a file pointer.  The stream is passed by reference.
*             By taking a stream as a parameter, this function can process input from stdin (manual input) or
*                 file pointers (automatic input) for the purpose of unit testing.
*
* RETURNS:	  The number of characters, alphabet letters or not, that were input.
*             For example:
*                 Input:  abc^Q			Return:  4			Explanation:  ^Q (AKA Ctrl-Q, 17) counts as character input
*                 Input:  90IOS^Q		Return:  6			Explanation:  ^Q (AKA Ctrl-Q, 17) counts as character input
*                 Input:  something\n
*                         ^Q			Return:  11			Explanation:  Pressing enter before ^Q (AKA Ctrl-Q, 17) registers as \n input and should be counted
*                 Input:  ^Q			Return:  1			Explanation:  Even without input, ^Q (AKA Ctrl-Q, 17) counts as character input
*             Return ERR_NULL_POINTER if inputStream is NULL
*
* NOTES:      Not only does this function return the total number of characters that were read from the stream "inputStream",
*                 this function should also update the character count in the global char array alphabetCount[].
*             First, uppercase 'A' is technically a different value than a lowercase 'a'.  To avoid this issue, change
*                 the case of all input to uppercase or lowercase (your discretion).
*                     Option #1 - The C library contains functions that will change the case of input.  Research and utilize this library function if you wish.
*                     Option #2 - Changing the case of a letter is a relatively easy algorithm when you consider the decimal value for char values.
*                         Feel free to write your own algorithm and/or function to change the case of your input if you wish.
*                     NOTE:  Regardless of the option you choose, there are only 26 elements in the global array so you'll have to count capitals
*                         and lowercase input in the same index.
*             Second, each element in alphabetCount[] counts the number of occurences for a letter of the alphabet.  Element 0 represents A and
*                 element 25 represents Z.  This means the value at element 0 represents the total number of As that have been counted.
*                 The value at element 7, as another example, represents the number of Hs that have been read.  Another example is that the value of
*                 alphabetCount[10] represents the number of letter Ks that have been counted.  Increment the approrpiate alphabetCount element based on
*                 the alphabet letter that has been counted.
*             Third, stop taking input upon receiving decimal value 17 (AKA Ctrl-Q).  Decimal value 17 may be replicated by manually inputting Ctrl-Q as input.
*                 The character input of 17 (AKA Ctrl-Q) should count towards the overall character input and should not be ignored.
*             Fourth, ensure you check if inputStream is NULL.  If inputStream is NULL, return ERR_NULL_POINTER.
*             Fifth, stop looping through stream input if you input an EOF.  EOF stands for End of File.  EOF is #defined to represent the end of a file.
*/
int count_input(FILE * inputStream)
{
	if (inputStream) // If inputStream is not NULL...
	{
		rewind(inputStream); // Moves the file pointer to the beginning of the file.  This is necessary for reading one file multiple times.

		int count = 0;
		char inputCharacter = 0;

		while (inputCharacter != 17)
		{
			inputCharacter = getc(inputStream);
			if (inputCharacter != EOF)
			{
				inputCharacter = toupper(inputCharacter);
				

				if (inputCharacter >= 'A' || inputCharacter <= 'Z')
				{
					alphabetCount[inputCharacter - 65]++;
					count++;
				}
			}
			else
			{
				break;
			}
		}
		
		return count;  // Modify this return statement
	}

	return ERR_NULL_POINTER;  // Modify this return statement
}

/*
* FUNCTION:   int clear_global_array(int currentAlphaCount)
*
* ARGUMENTS:  currentAlphaCount represents the expected sum of the alphabetCount[] global array.  This function
*                 should perform it's own count of alphabetCount[] as it clears the array to verify no illegal
*                 modifications have taken place.
*
* RETURNS:	  1 if currentAlphaCount is equal to the sum performed. This sum should represent the total number of alphabet letters 
*                 [a-z, A-Z] that were stored in alphabetCount[]. Otherwise return ERR_COUNT_MISMATCH.
*
* NOTES:      First, this function sums in order to return, the total number of alphabet letters that were counted in alphabetCount[]
*             Second, this function should also 'zeroize' all the elements of this array
*/
int clear_global_array(int currentAlphaCount)
{
	int count = 0;

	for (int i = 0; i < 26; i++)
	{
		count += alphabetCount[i];
		alphabetCount[i] = 0;
	}

	if (count == currentAlphaCount)
	{
		return 1;
	}
	else
	{
		return ERR_COUNT_MISMATCH;
	}
}

/*
* FUNCTION:   int print_alphabet_count(int printTheCount)
*
* ARGUMENTS:  printTheCount is utilized as a binary flag.  If printTheCount is on (AKA non-zero), then print_alphabet_count()
*                 should print the character count to stdout.  If printTheCount == 0, then print_alphabet_count() shouldn't
*                 actually print anything to stdout.  The return value should be unchanged by the value passed into printTheCount.
*
* RETURNS:	  The sum of all values contained in all elements of alphabetCount[]
*                 This sum should represent the total number of alphabet letters [a-z, A-Z] that were stored in alphabetCount[]
*
* NOTES:      First, this function sums and returns the total number of alphabet letters that were counted in alphabetCount[]
*             Second, this function should also print the per-letter count to stdout if printTheCount is a non-zero value.
*             Third, this function should invoke clear_global_array() once the total number of alphabet letters have been summed
*                 and the per-letter count has been printed (if required by printTheCount).  clear_global_array() is defined
*                 later but should zeroize the global array.  If clear_global_array() returns ERR_COUNT_MISMATCH, print an error.
*/
int print_alphabet_count(int printTheCount)
{
	int count = 0;
	
	for (int i = 0; i < 26; i++)
	{
		count += alphabetCount[i];
		if (printTheCount)
		{
			fprintf(stdout, "%c:\t%d\n", i + 65, alphabetCount[i]);
		}
	}

	if (clear_global_array(count) == ERR_COUNT_MISMATCH)
	{
		fprintf(stdout, "There was an error printing the alphabet count.");
	}

	return count;
}