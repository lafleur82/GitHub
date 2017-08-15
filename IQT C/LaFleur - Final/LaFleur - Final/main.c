#include "Case_Manipulation.h"
#include <stdio.h>
#include <string.h>

//#define EXTRA_DEBUG				// Uncomment this for more feedback on array mismatches
#define DEFAULT_VALUE (char)254
#define SAFE_BUFF 128
#define MAX_VALUE ((unsigned int)(1 << ((sizeof(char) * 8) - 1)))
#define RUN_FUNC1_TEST			// unsigned int chg_alpha_case(unsigned int letter);
#define RUN_FUNC2_TEST			// char * chg_string_case(char * string_ptr);
#define RUN_FUNC3_TEST			// char * chg_starting_here(char * string_ptr, int start_here);

struct FUNC_1_TEST
{
	char inputChar;
	char outputChar;
	char expectedChar;
}; /* int chg_alpha_case(int letter) */

struct FUNC_2_TEST
{
	char * inputString;
//	char * outputString;
	char * expectedString;
	int arrayLength;
}; /* char * chg_string_case(char * string_ptr) */

struct FUNC_3_TEST
{
	char * inputString;
	int inputPosition;
	char * expected_ptr;
	char * expectedString;
	int arrayLength;
}; /* char * chg_starting_here(char * string_ptr, int start_here) */

int main(void)
{
	/* GENERAL VARIABLES */
	int i = 0;

	/* FUNCTION 1 TESTING - int chg_alpha_case(int letter) */
	// Test input creation
	struct FUNC_1_TEST func1Test0 = { 0x0, DEFAULT_VALUE, 0x0 };
	struct FUNC_1_TEST func1Test1 = { 0x9, DEFAULT_VALUE, 0x9 };
	struct FUNC_1_TEST func1Test2 = { 0xA, DEFAULT_VALUE, 0xA };
	struct FUNC_1_TEST func1Test3 = { 0x20, DEFAULT_VALUE, 0x20 };
	struct FUNC_1_TEST func1Test4 = { 0x30, DEFAULT_VALUE, 0x30 };
	struct FUNC_1_TEST func1Test5 = { 0x36, DEFAULT_VALUE, 0x36 };
	struct FUNC_1_TEST func1Test6 = { 0x39, DEFAULT_VALUE, 0x39 };
	struct FUNC_1_TEST func1Test7 = { 0x40, DEFAULT_VALUE, 0x40 };
	struct FUNC_1_TEST func1Test8 = { 0x41, DEFAULT_VALUE, 0x61 };
	struct FUNC_1_TEST func1Test9 = { 0x48, DEFAULT_VALUE, 0x68 };
	struct FUNC_1_TEST func1Test10 = { 0x5A, DEFAULT_VALUE, 0x7A };
	struct FUNC_1_TEST func1Test11 = { 0x5B, DEFAULT_VALUE, 0x5B };
	struct FUNC_1_TEST func1Test12 = { 0x60, DEFAULT_VALUE, 0x60 };
	struct FUNC_1_TEST func1Test13 = { 0x61, DEFAULT_VALUE, 0x41 };
	struct FUNC_1_TEST func1Test14 = { 0x6A, DEFAULT_VALUE, 0x4A };
	struct FUNC_1_TEST func1Test15 = { 0x7A, DEFAULT_VALUE, 0x5A };
	struct FUNC_1_TEST func1Test16 = { 0x7B, DEFAULT_VALUE, 0x7B };
	struct FUNC_1_TEST func1Test17 = { 0x7F, DEFAULT_VALUE, 0x7F };
	struct FUNC_1_TEST func1Test18 = { 0x80, DEFAULT_VALUE, 0x80 };
	struct FUNC_1_TEST func1Test19 = { 0xFE, DEFAULT_VALUE, 0xFE };
	struct FUNC_1_TEST func1Test20 = { 0xFF, DEFAULT_VALUE, 0xFF };
	struct FUNC_1_TEST func1Test21 = { MAX_VALUE, DEFAULT_VALUE, MAX_VALUE };

	struct FUNC_1_TEST * func1TestArray[] = { \
		&func1Test0, &func1Test1, &func1Test2, &func1Test3, \
		&func1Test4, &func1Test5, &func1Test6, &func1Test7, \
		&func1Test8, &func1Test9, &func1Test10, &func1Test11, \
		&func1Test12, &func1Test13, &func1Test14, &func1Test15, \
		&func1Test16, &func1Test17, &func1Test18, &func1Test19, \
		&func1Test20, &func1Test21
	};

	int numFunc1Tests = sizeof(func1TestArray) / sizeof((*(func1TestArray)));
	int numFunc1TestsRun = 0;
	int numFunc1TestsPassed = 0;
	struct FUNC_1_TEST * currentTest1 = NULL;

#ifdef RUN_FUNC1_TEST
	// Run and report on test completion
	printf("\n\nRUNNING FUNCTION 1 TESTS:\n");
	for (i = 0; i < numFunc1Tests; i++)
	{
		currentTest1 = (*(func1TestArray + i));
		if (currentTest1)
		{
			printf("    Func1 Test %02d:\t", i);
			currentTest1->outputChar = chg_alpha_case(currentTest1->inputChar);
			numFunc1TestsRun++;

			if (currentTest1->outputChar == currentTest1->expectedChar)
			{
				printf("[*] Success! Values are equal.\n");
				numFunc1TestsPassed++;
			}
			else
			{
				printf("[x] Test Failed! Results are not equal!\n");
				printf("\tInput:\t%c | Expected:\t%c | Received:\t%c\n", currentTest1->inputChar, currentTest1->expectedChar, currentTest1->outputChar);
			}
		}
		else
		{
			fprintf(stderr, "Function 1 Test %d struct pointer variable was NULL?!\n", i);
		}
	}

	// Provide overall score
	printf("END OF FUNCTION 1 TESTS\n");
	if (numFunc1Tests != numFunc1TestsRun)
	{
		fprintf(stderr, "\t***Error: Test Number Mismatch***\n");
	}
	printf("\tFunc1 Tests Run:\t%d\n", numFunc1TestsRun);
	printf("\tFunc1 Tests Passed:\t%d\n", numFunc1TestsPassed);
#endif /* RUN_FUNC1_TEST */


	/* FUNCTION 2 TESTING - char * chg_string_case(char * string_ptr) */
	// Test input creation
	//// Normal input
	char test2string0[] = { "This is just a normal string." };
	char test2output0[] = { "tHIS IS JUST A NORMAL STRING." };
	char test2string1[] = { "This is also merely a normal string." };
	char test2output1[] = { "tHIS IS ALSO MERELY A NORMAL STRING." };
	char test2string2[] = { "tHIS IS JUST A NORMAL STRING." };
	char test2output2[] = { "This is just a normal string." };
	char test2string3[] = { "tHIS IS ALSO MERELY A NORMAL STRING." };
	char test2output3[] = { "This is also merely a normal string." };
	struct FUNC_2_TEST func2Test0 = { test2string0, test2output0, sizeof(test2string0) };
	struct FUNC_2_TEST func2Test1 = { test2string1, test2output1, sizeof(test2string1) };
	struct FUNC_2_TEST func2Test2 = { test2string2, test2output2, sizeof(test2string2) };
	struct FUNC_2_TEST func2Test3 = { test2string3, test2output3, sizeof(test2string3) };
	//// No letters
	char test2string4[] = { "!@#$%^&*()<>?,./;':[]{}-=_+" };
	char test2output4[] = { "!@#$%^&*()<>?,./;':[]{}-=_+" };
	char test2string5[] = { "1234567890" };
	char test2output5[] = { "1234567890" };
	struct FUNC_2_TEST func2Test4 = { test2string4, test2output4, sizeof(test2string4) };
	struct FUNC_2_TEST func2Test5 = { test2string5, test2output5, sizeof(test2string5) };
	//// Non printable characters
	char test2string6[] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0x0 };
	char test2output6[] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0x0 };
	char test2string7[] = { 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0x0 };
	char test2output7[] = { 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0x0 };
	struct FUNC_2_TEST func2Test6 = { test2string6, test2output6, sizeof(test2string6) };
	struct FUNC_2_TEST func2Test7 = { test2string7, test2output7, sizeof(test2string7) };
	//// Hidden strings
	char test2string8[] = { "This is not the only sentence in this char array. There's another sentence hidden after the nul character." };
	test2string8[49] = 0x0;
	char test2output8[] = { "tHIS IS NOT THE ONLY SENTENCE IN THIS CHAR ARRAY. There's another sentence hidden after the nul character." };
	test2output8[49] = 0x0;
	char test2string9[] = { "tHIS IS NOT THE ONLY SENTENCE IN THIS CHAR ARRAY. There's another sentence hidden after the nul character." };
	test2string9[49] = 0x0;
	char test2output9[] = { "This is not the only sentence in this char array. There's another sentence hidden after the nul character." };
	test2output9[49] = 0x0;
	char test2string10[] = { "One. Two. Three." };
	test2string10[4] = 0x0;
	test2string10[9] = 0x0;
	char test2output10[] = { "oNE. Two. Three." };
	test2output10[4] = 0x0;
	test2output10[9] = 0x0;
	char test2string11[] = { "oNE. Two. Three." };
	test2string11[4] = 0x0;
	test2string11[9] = 0x0;
	char test2output11[] = { "One. Two. Three." };
	test2output11[4] = 0x0;
	test2output11[9] = 0x0;
	struct FUNC_2_TEST func2Test8 = { test2string8, test2output8, sizeof(test2string8) };
	struct FUNC_2_TEST func2Test9 = { test2string9, test2output9, sizeof(test2string9) };
	struct FUNC_2_TEST func2Test10 = { test2string10, test2output10, sizeof(test2string10) };
	struct FUNC_2_TEST func2Test11 = { test2string11, test2output11, sizeof(test2string11) };
	//// Zero length strings
	char test2string12[1] = { 0x0 };
	char test2output12[1] = { 0x0 };
	char test2string13[] = { 0x0, 0x41, 0x42, 0x43, 0x31, 0x32, 0x33, 0x0 };
	char test2output13[] = { 0x0, 0x41, 0x42, 0x43, 0x31, 0x32, 0x33, 0x0 };
	struct FUNC_2_TEST func2Test12 = { test2string12, test2output12, sizeof(test2string12) };
	struct FUNC_2_TEST func2Test13 = { test2string13, test2output13, sizeof(test2string13) };
	//// NOTE: Don't forget a NULL pointer
	struct FUNC_2_TEST func2Test14 = { NULL, NULL, 0 };
	//// Mixed input
	char test2string15[] = { "This string has it all:\n\tPrintable characters, non-printable characters, ______, hidden strings... the works! You shouldn't be changing anything back here!\nStop reading this!" };
	test2string15[73] = 232; // 0
	test2string15[74] = 124; // 1
	test2string15[75] = 253; // 2
	test2string15[76] = 227; // 3
	test2string15[77] = 252; // n
	test2string15[78] = 236; // infinity
	test2string15[108] = 0x0;
	char test2output15[] = { "tHIS STRING HAS IT ALL:\n\tpRINTABLE CHARACTERS, NON-PRINTABLE CHARACTERS, ______, HIDDEN STRINGS... THE WORKS! You shouldn't be changing anything back here!\nStop reading this!" };
	test2output15[73] = 232; // 0
	test2output15[74] = 124; // 1
	test2output15[75] = 253; // 2
	test2output15[76] = 227; // 3
	test2output15[77] = 252; // n
	test2output15[78] = 236; // infinity
	test2output15[108] = 0x0;
//	puts(test2output15); // DEBUGGING
	char test2string16[] = { 0x48, 0x61, 0x72, 0x6B, 0x3F, 0x9, 159, 230, 40, 204, 60, 0x0, 0x53, 0x74, 0x6F, 0x70, 0x21, 0x0 };
	char test2output16[] = { 0x68, 0x41, 0x52, 0x4B, 0x3F, 0x9, 159, 230, 40, 204, 60, 0x0, 0x53, 0x74, 0x6F, 0x70, 0x21, 0x0 };
//	puts(test2string16); // DEBUGGING
	struct FUNC_2_TEST func2Test15 = { test2string15, test2output15, sizeof(test2string15) };
	struct FUNC_2_TEST func2Test16 = { test2string16, test2output16, sizeof(test2string16) };


	struct FUNC_2_TEST * func2TestArray[] = { \
		&func2Test0, &func2Test1, &func2Test2, &func2Test3, \
		&func2Test4, &func2Test5, &func2Test6, &func2Test7, \
		&func2Test8, &func2Test9, &func2Test10, &func2Test11, \
		&func2Test12, &func2Test13, &func2Test14, &func2Test15, \
		&func2Test16
	};

	int numFunc2Tests = sizeof(func2TestArray) / sizeof((*(func2TestArray)));
	int numFunc2TestsRun = 0;
	int numFunc2TestsPassed = 0;
	struct FUNC_2_TEST * currentTest2 = &func2Test0;
	char * tempReturnValue2 = NULL;

#ifdef RUN_FUNC2_TEST
	// Run and report on test completion
	printf("\n\nRUNNING FUNCTION 2 TESTS:\n");
	for (i = 0; i < numFunc2Tests; i++)
	{
		currentTest2 = (*(func2TestArray + i));
		if (currentTest2)
		{
			printf("    Func2 Test %02d:\t", i);
			tempReturnValue2 = chg_string_case(currentTest2->inputString);
			numFunc2TestsRun++;

			if (currentTest2->expectedString != NULL && tempReturnValue2 != NULL)
			{
				if (!(memcmp(currentTest2->expectedString, tempReturnValue2, currentTest2->arrayLength)))
				{
					printf("[*] Success! Arrays are equivalent.\n");
					numFunc2TestsPassed++;
				}
				else
				{
					printf("[x] Test Failed! Array mismatch!\n");
					printf("\tExpected:\t%s\n\tReceived:\t%s\n", currentTest2->expectedString, tempReturnValue2);
				}
			}
			else
			{
				if (currentTest2->expectedString == tempReturnValue2)
				{
					printf("[*] Success! Pointers are equivalent.\n");
					numFunc2TestsPassed++;
				}
				else
				{
					printf("[x] Test Failed! Pointer mismatch!\n");
					printf("\tExpected:\t");
					if (currentTest2->expectedString == NULL)
					{
						printf("NULL\n\t");
					}
					else
					{
						printf("%s\n\t", currentTest2->expectedString);
					}
					printf("Received:\t");
					if (tempReturnValue2 == NULL)
					{
						printf("NULL\n");
					}
					else
					{
						printf("%s\n", tempReturnValue2);
					}
				}
			}
		}
		else
		{
			fprintf(stderr, "Function 2 Test %d struct pointer variable was NULL?!\n", i);
		}
	}

	// Provide overall score
	printf("END OF FUNCTION 2 TESTS\n");
	if (numFunc2Tests != numFunc2TestsRun)
	{
		fprintf(stderr, "\t***Error: Test Number Mismatch***\n");
	}
	printf("\tFunc2 Tests Run:\t%d\n", numFunc2TestsRun);
	printf("\tFunc2 Tests Passed:\t%d\n", numFunc2TestsPassed);
#endif /* RUN_FUNC2_TEST */


	/* FUNCTION 3 TESTING - char * chg_starting_here(char * string_ptr, int start_here) */
	// Test input creation
	//// Normal input
	char test3string0[] = { "This is just a normal string." };
	char test3output0[] = { "This IS JUST A NORMAL STRING." };
	char test3string1[] = { "This is also merely a normal string." };
	char test3output1[] = { "This is ALSO MERELY A NORMAL STRING." };
	char test3string2[] = { "tHIS IS JUST A NORMAL STRING." };
	char test3output2[] = { "tHIS IS JUst a normal string." };
	char test3string3[] = { "tHIS IS ALSO MERELY A NORMAL STRING." };
	char test3output3[] = { "tHIS IS ALSO MERely a normal string." };
	struct FUNC_3_TEST func3Test0 = { test3string0, 4, test3string0 + 4, test3output0, sizeof(test3string0) };
	struct FUNC_3_TEST func3Test1 = { test3string1, 8, test3string1 + 8, test3output1, sizeof(test3string1) };
	struct FUNC_3_TEST func3Test2 = { test3string2, 10, test3string2 + 10, test3output2, sizeof(test3string2) };
	struct FUNC_3_TEST func3Test3 = { test3string3, 16, test3string3 + 16, test3output3, sizeof(test3string3) };
	//// No letters
	char test3string4[] = { "!@#$%^&*()<>?,./;':[]{}-=_+" };
	char test3output4[] = { "!@#$%^&*()<>?,./;':[]{}-=_+" };
	char test3string5[] = { "1234567890" };
	char test3output5[] = { "1234567890" };
	struct FUNC_3_TEST func3Test4 = { test3string4, 0, test3string4, test3output4, sizeof(test3string4) };
	struct FUNC_3_TEST func3Test5 = { test3string5, 0, test3string5, test3output5, sizeof(test3string5) };
	//// Non printable characters
	char test3string6[] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0x0 };
	char test3output6[] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0x0 };
	char test3string7[] = { 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0x0 };
	char test3output7[] = { 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0x0 };
	struct FUNC_3_TEST func3Test6 = { test3string6, 0, test3string6, test3output6, sizeof(test3string6) };
	struct FUNC_3_TEST func3Test7 = { test3string7, 0, test3string7, test3output7, sizeof(test3string7) };
	//// Hidden strings
	char test3string8[] = { "This is not the only sentence in this char array. There's another sentence hidden after the nul character." };
	test3string8[49] = 0x0;
	char test3output8[] = { "tHIS IS NOT THE ONLY SENTENCE IN THIS CHAR ARRAY. There's another sentence hidden after the nul character." };
	test3output8[49] = 0x0;
	char test3string9[] = { "tHIS IS NOT THE ONLY SENTENCE IN THIS CHAR ARRAY. There's another sentence hidden after the nul character." };
	test3string9[49] = 0x0;
	char test3output9[] = { "This is not the only sentence in this char array. There's another sentence hidden after the nul character." };
	test3output9[49] = 0x0;
	char test3string10[] = { "One. Two. Three." };
	test3string10[4] = 0x0;
	test3string10[9] = 0x0;
	char test3output10[] = { "oNE. Two. Three." };
	test3output10[4] = 0x0;
	test3output10[9] = 0x0;
	char test3string11[] = { "oNE. Two. Three." };
	test3string11[4] = 0x0;
	test3string11[9] = 0x0;
	char test3output11[] = { "One. Two. Three." };
	test3output11[4] = 0x0;
	test3output11[9] = 0x0;
	struct FUNC_3_TEST func3Test8 = { test3string8, 0, test3string8, test3output8, sizeof(test3string8) };
	struct FUNC_3_TEST func3Test9 = { test3string9, 0, test3string9, test3output9, sizeof(test3string9) };
	struct FUNC_3_TEST func3Test10 = { test3string10, 0, test3string10, test3output10, sizeof(test3string10) };
	struct FUNC_3_TEST func3Test11 = { test3string11, 0, test3string11, test3output11, sizeof(test3string11) };
	//// Zero length strings
	char test3string12[1] = { 0x0 };
	char test3output12[1] = { 0x0 };
	char test3string13[] = { 0x0, 0x41, 0x42, 0x43, 0x31, 0x32, 0x33, 0x0 };
	char test3output13[] = { 0x0, 0x41, 0x42, 0x43, 0x31, 0x32, 0x33, 0x0 };
	struct FUNC_3_TEST func3Test12 = { test3string12, 0, NULL, test3output12, sizeof(test3string12) };
	struct FUNC_3_TEST func3Test13 = { test3string13, 0, NULL, test3output13, sizeof(test3string13) };
	//// NOTE: Don't forget a NULL pointer
	struct FUNC_3_TEST func3Test14 = { NULL, 0, NULL, 0 };
	//// Mixed input
	char test3string15[] = { "This string has it all:\n\tPrintable characters, non-printable characters, ______, hidden strings... the works! You shouldn't be changing anything back here!\nStop reading this!" };
	test3string15[73] = 232; // 0
	test3string15[74] = 124; // 1
	test3string15[75] = 253; // 2
	test3string15[76] = 227; // 3
	test3string15[77] = 252; // n
	test3string15[78] = 236; // infinity
	test3string15[108] = 0x0;
	char test3output15[] = { "tHIS STRING HAS IT ALL:\n\tpRINTABLE CHARACTERS, NON-PRINTABLE CHARACTERS, ______, HIDDEN STRINGS... THE WORKS! You shouldn't be changing anything back here!\nStop reading this!" };
	test3output15[73] = 232; // 0
	test3output15[74] = 124; // 1
	test3output15[75] = 253; // 2
	test3output15[76] = 227; // 3
	test3output15[77] = 252; // n
	test3output15[78] = 236; // infinity
	test3output15[108] = 0x0;
	//	puts(test3output15); // DEBUGGING
	char test3string16[] = { 0x48, 0x61, 0x72, 0x6B, 0x3F, 0x9, 159, 230, 40, 204, 60, 0x0, 0x53, 0x74, 0x6F, 0x70, 0x21, 0x0 };
	char test3output16[] = { 0x68, 0x41, 0x52, 0x4B, 0x3F, 0x9, 159, 230, 40, 204, 60, 0x0, 0x53, 0x74, 0x6F, 0x70, 0x21, 0x0 };
	//	puts(test3string16); // DEBUGGING
	struct FUNC_3_TEST func3Test15 = { test3string15, 0, test3string15, test3output15, sizeof(test3string15) };
	struct FUNC_3_TEST func3Test16 = { test3string16, 0, test3string16, test3output16, sizeof(test3string16) };
	//// Normal strings with unreasonable lengths
	char test3string17[SAFE_BUFF] = { "Normal string.  Bad starting point." };
	char test3output17[SAFE_BUFF] = { "Normal string.  Bad starting point." };
	char test3string18[SAFE_BUFF] = { "This is a reasonable string but the length that got passed is unreasonable.\0DON'T DO IT!1!!!1!!eleven!1!!!" };
	char test3output18[SAFE_BUFF] = { "This is a reasonable string but the length that got passed is unreasonable.\0DON'T DO IT!1!!!1!!eleven!1!!!" };
	char test3string19[SAFE_BUFF] = { "I hope you didn't modify this string because the starting position is out of bounds.\0hIdDeN sTrInG!1!\0" };
	char test3output19[SAFE_BUFF] = { "I hope you didn't modify this string because the starting position is out of bounds.\0hIdDeN sTrInG!1!\0" };
	char test3string20[SAFE_BUFF] = { "Dont' modify this string.  You're going to have a bad time." };
	char test3output20[SAFE_BUFF] = { "Dont' modify this string.  You're going to have a bad time." };
	char test3string21[] = { "Don't do it!" };
	char test3output21[] = { "Don't do it!" };
	struct FUNC_3_TEST func3Test17 = { test3string17, 35, NULL, test3output17, sizeof(test3string17) };
	struct FUNC_3_TEST func3Test18 = { test3string18, 76, NULL, test3output18, sizeof(test3string18) };
	struct FUNC_3_TEST func3Test19 = { test3string19, 85, NULL, test3output19, sizeof(test3string19) };
	struct FUNC_3_TEST func3Test20 = { test3string20, (SAFE_BUFF - 1), NULL, test3output20, sizeof(test3string20) };
	struct FUNC_3_TEST func3Test21 = { test3string21, 90318, NULL, test3output21, sizeof(test3string21) };


	struct FUNC_3_TEST * func3TestArray[] = { \
		&func3Test0, &func3Test1, &func3Test2, &func3Test3, \
		&func3Test4, &func3Test5, &func3Test6, &func3Test7, \
		&func3Test8, &func3Test9, &func3Test10, &func3Test11, \
		&func3Test12, &func3Test13, &func3Test14, &func3Test15, \
		&func3Test16, &func3Test17, &func3Test18, &func3Test19, \
		&func3Test20, &func3Test21
	};

	int numfunc3Tests = sizeof(func3TestArray) / sizeof((*(func3TestArray)));
	int numfunc3TestsRun = 0;
	int numfunc3TestsPassed = 0;
	struct FUNC_3_TEST * currentTest3 = &func3Test0;
	char * tempReturnValue3 = NULL;

#ifdef RUN_FUNC3_TEST
	// Run and report on test completion
	printf("\n\nRUNNING FUNCTION 3 TESTS:\n");
	for (i = 0; i < numfunc3Tests; i++)
	{
		currentTest3 = (*(func3TestArray + i));
		if (currentTest3)
		{
			printf("    Func3 Test %02d:\t", i);
			tempReturnValue3 = chg_starting_here(currentTest3->inputString, currentTest3->inputPosition);
			numfunc3TestsRun++;

			if (currentTest3->expectedString != NULL && currentTest3->expected_ptr != NULL && tempReturnValue3 != NULL)
			{
				if ((!(memcmp(currentTest3->expectedString, currentTest3->inputString, currentTest3->arrayLength))) && \
					(tempReturnValue3 == currentTest3->expected_ptr))
				{
					printf("[*] Success! Arrays are equivalent.\n");
					numfunc3TestsPassed++;
				}
				else
				{
#ifdef EXTRA_DEBUG
					puts("Something went wrong.");
					printf("Expected:\t%s\n", currentTest3->expectedString);
					printf("Modified:\t%s\n", currentTest3->inputString);
					for (i = 0; i < currentTest3->arrayLength; i++)
					{
						if ((*((currentTest3->expectedString) + i)) != (*((currentTest3->inputString) + i)))
						{
							printf("Index %d is not equal.  Expected: %c\tReceived:\t%d\n", i, (*((currentTest3->expectedString) + i)), (*((currentTest3->inputString) + i)));
						}
					}
#endif // EXTRA_DEBUG
					printf("[x] Test Failed! Array mismatch!\n");
					printf("\tExpected: (%p) \t%s\n\tReceived: (%p) \t%s\n", currentTest3->expected_ptr, currentTest3->expected_ptr, tempReturnValue3, tempReturnValue3);
				}
			}
			else
			{
				if (currentTest3->expected_ptr == tempReturnValue3)
				{
					printf("[*] Success! Pointers are equivalent.\n");
					numfunc3TestsPassed++;
				}
				else
				{
					printf("[x] Test Failed! Pointer mismatch!\n");
					if (currentTest3->expected_ptr == NULL)
					{
						printf("\tExpected: (%p) \tNULL\n", currentTest3->expected_ptr);
					}
					else
					{
						printf("\tExpected: (%p) \t%s\n", currentTest3->expected_ptr, currentTest3->expected_ptr);
					}
					if (tempReturnValue3 == NULL)
					{
						printf("\tReceived: (%p) \tNULL\n", tempReturnValue3);
					}
					else
					{
						printf("\tReceived: (%p) \t%s\n", tempReturnValue3, tempReturnValue3);
					}
				}
			}
		}
		else
		{
			fprintf(stderr, "Function 3 Test %d struct pointer variable was NULL?!\n", i);
		}
	}

	// Provide overall score
	printf("END OF FUNCTION 3 TESTS\n");
	if (numfunc3Tests != numfunc3TestsRun)
	{
		fprintf(stderr, "\t***Error: Test Number Mismatch***\n");
	}
	printf("\tFunc3 Tests Run:\t%d\n", numfunc3TestsRun);
	printf("\tFunc3 Tests Passed:\t%d\n", numfunc3TestsPassed);
#endif /* RUN_FUNC3_TEST */

	getchar(); getchar();
	return 0;
}
