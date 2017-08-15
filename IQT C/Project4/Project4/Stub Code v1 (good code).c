////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// PERFORMANCE LAB I.7.A-2 /////////////////////////////////////////////
///////////////////////////////////////////////// ARRAYS OF STRUCTS ////////////////////////////////////////////////
////////////////////////////////////// "Good Order, Discipline, and Structure" /////////////////////////////////////
/////////////////////////////////////////////// Stub Code (good code) //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Reaccomplish (or modify) Performance Lab I.5.a-5 (see below) with the following stipulations:
//     Define a struct to test counting_array() (see below) from Performance Lab I.5.a-5
//     Utilize an array of struct pointers to store all of the structs you create as tests
//     Only Address Arithmetic is permitted
//     Write at least one test to cover every requirement
//     Print the human-readable output
//     Use of the dot operator (.) is expressly FORBIDDEN.  You are only allowed to use the arrow (->) operator
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// PERFORMANCE LAB I.5.A-5 ////////////////////////////////////////////
//////////////////////////////////////////////////// POINTER ARRAYS ////////////////////////////////////////////////
////////////////////////////////////////////// "Good Order and Discipline" /////////////////////////////////////////
/////////////////////////////////////////////// Stub Code (good code) //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The student is required to write tests in main() that will test counting_array()
// The version of counting_array() in this solution is 100% functional
// The student will write parallel arrays of test parameters for counting_array() which, at a minimum, includes:
//     inputStartingNumbers - A parallel integer array of "starting numbers"
//     inputEndingNumbers - A parallel integer array of "ending numbers"
//     expectedErrorCodes - A parallel integer array of expected "error codes"
//     expectedIntArrays - A parallel array of integer arrays which holds the expected output
// Execution of the testing should be accomplished by looping through the parallel arrays.  Each iteration of the
//     loop should:
//         1. Invoke counting_array() with a starting number, an ending number, and an integer pointer to store
//             the resulting errorCode.
//         2. Test the dereferenced value of the integer pointer against what is expected.
//         3. Test the returned integer pointer against what is expected.
//         4. Report the results:
//             Printing "Pass" (and counting it) is sufficient when a test passes.
//             On a failed test, print the test that failed (e.g., Return Value, errorCode), print "FAIL",
//             print the expected output, and print the value that was found/received.
//         5. Count the number of passes and the number of tests (for a summary)
// At the end of all the testing, print (in a human-readable format) the total number of tests that were run and
//     the total number of tests that passed.
// 
// TESTING SPECIFICATIONS
// Write one test for each of the following conditions:
// Test #		startingNumber		endingNumber		expectedErrorCode
// 1.			x					y					0
// 2.			a					y					0
// 3.			a					b					0
// 4.			y					x					-2
// 5.			b					a					-2
// 6.			y					a					-2
// NOTE 1:  If a < b < 0 < x < y
// NOTE 2:  The values of a, b, x, and y don't have to be the same each time.  In fact, it's best for testing
//     if they're not always the same.
// All reference to arrays and the elements of those arrays *MUST* be accomplished utilizing
//     Address Arithmetic (AKA pointer math).  e.g., *NO* "myArray[i]" is permitted.
//
// NOTE:  counting_array() has been written with good code *and* bad code so that students can practice both
//     conditions as they write their tests.  This version of counting_array() happens to be the version that 
//     passes all tests as listed.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#elif defined(__linux__) || defined(__unix__)
#include <unistd.h>
#endif

//function declarations

int * counting_array(int startingNumber, int endingNumber, int * errorCode);


//structs

struct TestFunction
{
	int testNumber;

	int input_startingNumber_ptr;
	int input_endingNumber_ptr;
	int input_errorCode_ptr;

	int * expected_return_ptr;
	int expected_dimension_ptr;
	int expected_errorCode_ptr;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     Utilize an array of struct pointers to store all of the structs you create as tests
//     Only Address Arithmetic is permitted
//     Write at least one test to cover every requirement
//     Print the human-readable output
//     Use of the dot operator (.) is expressly FORBIDDEN.  You are only allowed to use the arrow (->) operator
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	int * tempReturn_ptr = NULL;		// Holds the return value for each execution of counting_array()
	int * tempInput_ptr = NULL;			// Holds the pointer to an integer array that tempReturnPointer_ptr should match
	int tempErrorCode = 0;				// Holds the error code provided by counting_array()
	struct TestFunction input1;			// Test #1
	struct TestFunction input2;			// Test #2
	struct TestFunction input3;			// Test #3
	struct TestFunction input4;			// Test #4
	struct TestFunction input5;			// Test #5
	struct TestFunction input6;			// Test #6
	struct TestFunction * currentTest;	// stores current input being populated
	int fail = 0;						// fail > 0 will indicate there was a failure in the test
	int numOfTestsRun = 0;				// Number of tests that have run
	int numOfTestsPassed = 0;			// Number of tests that have passed
	int i = 0;							// loop counter
	int j = 0;							// loop counter


	// populating the input structs for testing

	/* Input 1 */
	currentTest = &input1;
	int expectedOutput1[318 - 90 + 1] = { 0 };
	currentTest->testNumber = 1;
	currentTest->input_startingNumber_ptr = 90;
	currentTest->input_endingNumber_ptr = 318;
	currentTest->expected_errorCode_ptr = 0;
	currentTest->expected_dimension_ptr = (318 - 90 + 1);
	currentTest->expected_return_ptr = expectedOutput1;

	for (int i = 0; i < currentTest->expected_dimension_ptr; i++)
	{
		*(expectedOutput1 + i) = (currentTest->input_startingNumber_ptr + i);
	}

	/* Input 2 */
	currentTest = &input2;
	int expectedOutput2[688 + 24 + 1] = { 0 };
	currentTest->testNumber = 2;
	currentTest->input_startingNumber_ptr = -24;
	currentTest->input_endingNumber_ptr = 688;
	currentTest->expected_errorCode_ptr = 0;
	currentTest->expected_dimension_ptr = (688 + 24 + 1);
	currentTest->expected_return_ptr = expectedOutput2;

	for (int i = 0; i < currentTest->expected_dimension_ptr; i++)
	{
		*(expectedOutput2 + i) = (currentTest->input_startingNumber_ptr + i);
	}

	/* Input 3 */
	currentTest = &input3;
	int expectedOutput3[688 - 318 + 1] = { 0 };
	currentTest->testNumber = 3;
	currentTest->input_startingNumber_ptr = -688;
	currentTest->input_endingNumber_ptr = -318;
	currentTest->expected_errorCode_ptr = 0;
	currentTest->expected_dimension_ptr = (688 - 318 + 1);
	currentTest->expected_return_ptr = expectedOutput3;

	for (int i = 0; i < currentTest->expected_dimension_ptr; i++)
	{
		*(expectedOutput3 + i) = (currentTest->input_startingNumber_ptr + i);
	}
	
	/* Input 4 */
	currentTest = &input4;
	int expectedOutput4 = NULL;
	currentTest->testNumber = 4;
	currentTest->input_startingNumber_ptr = 688;
	currentTest->input_endingNumber_ptr = 318;
	currentTest->expected_errorCode_ptr = -2;
	currentTest->expected_dimension_ptr = 0;
	currentTest->expected_return_ptr = expectedOutput4;
	
	/* Input 5 */
	currentTest = &input5;
	int * expectedOutput5 = NULL;
	currentTest->testNumber = 5;
	currentTest->input_startingNumber_ptr = -90;
	currentTest->input_endingNumber_ptr = -318;
	currentTest->expected_errorCode_ptr = -2;
	currentTest->expected_dimension_ptr = 0;
	currentTest->expected_return_ptr = expectedOutput5;

	/* Input 6 */
	currentTest = &input6;
	int * expectedOutput6 = NULL;
	currentTest->testNumber = 6;
	currentTest->input_startingNumber_ptr = 688;
	currentTest->input_endingNumber_ptr = -24;
	currentTest->expected_errorCode_ptr = -2;
	currentTest->expected_dimension_ptr = 0;
	currentTest->expected_return_ptr = expectedOutput6;


	/* Array of structs that hold test input */

	struct TestFunction * inputArray[] = { &input1, &input2, &input3, &input4, &input5, &input6 };


	// test against each input in the the array

	for (i = 0; i < sizeof(inputArray) / sizeof(*inputArray); i++)
	{
		printf("INPUT #%02d\n", (*(inputArray + i))->testNumber);
		printf("\tArray Results:\t");

		numOfTestsRun++;
		tempReturn_ptr = counting_array((*(inputArray + i))->input_startingNumber_ptr, (*(inputArray + i))->input_endingNumber_ptr, &tempErrorCode);
		tempInput_ptr = (*(inputArray + i))->expected_return_ptr;

		//loops through the array and checks to see if they are the same
		for (j = 0; j < (*(inputArray + i))->expected_dimension_ptr; j++)
		{
			if (tempReturn_ptr && tempInput_ptr) // if both pointers are not null
			{
				// if the value of an element in the returned array doesn't match the expected array value
				if (*(tempReturn_ptr + j) != *(tempInput_ptr + j)) 
				{
					fail++;	// increment fail condition
					break;  // and break out of the loop
				}
			}
			else
			{
				// if the pointers don't match
				if (tempReturn_ptr != tempInput_ptr) 
				{
					fail++;	// increment fail condition
					break;  // and break out of the loop
				}
			}
		}

		if (fail)
		{
			printf("FAIL\n\t\t");
			if (tempInput_ptr)
			{
				printf("\tExpected Value %d at Index[%d]\n\t\t", *(tempInput_ptr + j), j);
			}
			else
			{
				printf("\tExpected a NULL pointer\n\t\t");
			}

			if (tempReturn_ptr)
			{
				printf("\tReceived Value %d at Index[%d]\n", *(tempReturn_ptr + j), j);
			}
			else
			{
				printf("\tReceived a NULL pointer\n");
			}

			free(tempReturn_ptr);
		}
		else
		{
			printf("\tPass.\n");
			numOfTestsPassed++;	// increment passed test counter
		}

		fail = 0; //reset for next loop
	}

	getchar();
	return 0;
}

/*
 * FUNCTION:   int * counting_array(int startingNumber, int endingNumber, int * errorCode)
 *
 * ARGUMENTS:  First, it's important to note that successful execution of counting_array() will result
 *                 in an integer array filled with values starting with "startingNumber" and ending in
 *                 "endingNumber".  The dimension of this integer array is determined by these values.
 *                 Successful execution of counting_array() will result a pointer to an integer array
 *                 with a dimension equal to (endingNumber - startingNumber + 1);
 *			   startingNumber indicates the value of index 0 within the integer array mentioned above
 *             endingnumber indicates the value of the last index within the integer array mentioned above
 *             errorCode is an integer pointer to store the errorCode provided by counting_array() (see NOTES)
 *
 * RETURNS:	   On success, integer pointer to an integer array of dimension (endingNumber - startingNumber + 1).
 *                 The values of the integer array found at the integer pointer will be sequential.
 *                 If the return pointer is stored in int * returnArray_ptr, the following statements
 *                 will be true:
 *                     returnArray_ptr[0] == startingNumber;
 *                     returnArray_ptr[endingNumber - startingNumber] == endingNumber;
 *                     returnArray_ptr[0] + 1 == returnArray_ptr[1];
 *             On failure, counting_array() returns NULL.  (see errorCode description for examples of
 *                 potential failures)
 *
 * NOTES:      Error Codes:
 *                 0 on success
 *                 -2 if startingNumber is greater than endingNumber
 *                 -3 for all other errors (this may not be a testable condtion.
 */
int * counting_array(int startingNumber, int endingNumber, int * errorCode)
{
	int * returnValue_ptr = NULL;	// Return value variable
	int returnErrorCode = 0;		// Return error code variable
	int i = 0;						// Iterating variable
	int tempArrayDimension = 0;		// Variable which holds the calculated dimension of the int array to return

	if (!errorCode)					// If the int pointer is NULL...
	{
		returnValue_ptr = NULL;		// ...set the return value as NULL and...
		returnErrorCode = -1;		// ...set the error code variable to -1
	}
	if (startingNumber > endingNumber)	// If the start number is greater than the end number...
	{
		returnValue_ptr = NULL;			// ...set the return value as NULL and...
		returnErrorCode = -2;			// ...set the error code variable to -2
	}
	else // Otherwise, the parameters are fine (so far)
	{
		tempArrayDimension = endingNumber - startingNumber + 1; // Compute the dimension of the int array to return

		/* Paranoid error check */
		if (tempArrayDimension > 0) // If the calculated dimension is valid...
		{
			returnValue_ptr = (int *)calloc(tempArrayDimension, sizeof(int)); // Dynamically allocate initialized memory into an appropriately sized int array

			/* Semi-Paranoid error check */
			if (returnValue_ptr) // If calloc actually returned a pointer to valid memory space...
			{
				/* ...initialize that int array with the appropriate values */
				for (i = 0; i < tempArrayDimension; i++)
				{
					*(returnValue_ptr + i) = (startingNumber + i);
				}
			}
			else // Otherwise, calloc messed up so...
			{
				returnValue_ptr = NULL; // ...return NULL and...
				returnErrorCode = -3;	// ...set the error code to -3 (which should be a very rare occurrence)
			}
		}
	}
	
	if (errorCode) // If errorCode is *NOT* NULL...
	{
		*errorCode = returnErrorCode; // ...set the value at that memory address to the error code variable value
	}
	return returnValue_ptr;
}
