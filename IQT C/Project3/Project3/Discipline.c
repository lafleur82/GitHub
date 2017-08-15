////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// PERFORMANCE LAB I.5.A-5 ////////////////////////////////////////////
//////////////////////////////////////////////////// POINTER ARRAYS ////////////////////////////////////////////////
////////////////////////////////////////////// "Good Order and Discipline" /////////////////////////////////////////
////////////////////////////////////////////////// Stub Code (good code) ///////////////////////////////////////////
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
int * counting_array(int startingNumber, int endingNumber, int * errorCode);

struct Input
{
	int inputNumber;		// Test #
	int startNumber;		// Value for startingNumber parameter
	int endNumber;			// Value for endingNumber parameter
	int expectedErrorCode;	// Value for expected error code
	int expectedDimension;	// Expected dimension of returned int array
	int * expectedResult;	// Integer pointer to an int array that should mirror the returned array
};

int main(void)
{
	int * tempReturnPointer_ptr = NULL;	// Holds the return value for each execution of 
	int * tempInputPointer_ptr = NULL;	// Holds the pointer to an integer array that tempReturnPointer_ptr should match
	int tempErrorCode = 0;				// Holds the error code provided by counting_array()
	struct Input input1;				// Test #1
	struct Input input2;				// Test #2
	struct Input input3;				// Test #3
	struct Input input4;				// Test #4
	struct Input input5;				// Test #5
	struct Input input6;				// Test #6
	int i = 0;							// Iterating variable
	int j = 0;							// Iterating variable
	int anyMismatches = 0;				// Boolean-style variable to indicate any mismatch between the expected int array and the returned int array
	int numOfTestsRun = 0;				// Number of tests that have run
	int numOfTestsPassed = 0;			// Number of tests that have passed

	/* Input 1 */
	int expectedOutput1[318 - 90 + 1] = { 0 };
	input1.inputNumber = 1;
	input1.startNumber = 90;
	input1.endNumber = 318;
	input1.expectedErrorCode = 0;
	input1.expectedDimension = (318 - 90 + 1);
	input1.expectedResult = expectedOutput1;
	for (i = 0; i < input1.expectedDimension; i++)
	{
		*(expectedOutput1 + i) = (input1.startNumber + i);
	}

	/* Input 2 */
	int expectedOutput2[688 + 24 + 1] = { 0 };
	input2.inputNumber = 2;
	input2.startNumber = -24;
	input2.endNumber = 688;
	input2.expectedErrorCode = 0;
	input2.expectedDimension = (688 + 24 + 1);
	input2.expectedResult = expectedOutput2;
	for (i = 0; i < input2.expectedDimension; i++)
	{
		*(expectedOutput2 + i) = (input2.startNumber + i);
	}

	/* Input 3 */
	int expectedOutput3[688 - 318 + 1] = { 0 };
	input3.inputNumber = 3;
	input3.startNumber = -688;
	input3.endNumber = -318;
	input3.expectedErrorCode = 0;
	input3.expectedDimension = (688 - 318 + 1);
	input3.expectedResult = expectedOutput3;
	for (i = 0; i < input3.expectedDimension; i++)
	{
		*(expectedOutput3 + i) = (input3.startNumber + i);
	}

	/* Input 4 */
	int * expectedOutput4 = NULL;
	input4.inputNumber = 4;
	input4.startNumber = 688;
	input4.endNumber = 318;
	input4.expectedErrorCode = -2;
	input4.expectedDimension = 0;
	input4.expectedResult = expectedOutput4;

	/* Input 5 */
	int * expectedOutput5 = NULL;
	input5.inputNumber = 5;
	input5.startNumber = -90;
	input5.endNumber = -318;
	input5.expectedErrorCode = -2;
	input5.expectedDimension = 0;
	input5.expectedResult = expectedOutput5;

	/* Input 6 */
	int * expectedOutput6 = NULL;
	input6.inputNumber = 6;
	input6.startNumber = 688;
	input6.endNumber = -24;
	input6.expectedErrorCode = -2;
	input6.expectedDimension = 0;
	input6.expectedResult = expectedOutput6;
	
	/* Array of structs that hold test input */
	struct Input * inputArray[] = { &input1, &input2, &input3, &input4, &input5, &input6 };

	for (i = 0; i < sizeof(inputArray) / sizeof(*inputArray); i++)
	{
		printf("INPUT #%02d\n", (*(inputArray + i))->inputNumber);

		tempReturnPointer_ptr = counting_array((*(inputArray + i))->startNumber, (*(inputArray + i))->endNumber, &tempErrorCode);


		/* ARRAY TEST */
		numOfTestsRun++;
		printf("\tArray Results:\t");

		tempInputPointer_ptr = (*(inputArray + i))->expectedResult;
		for (j = 0; j < (*(inputArray + i))->expectedDimension; j++)
		{
			if (tempReturnPointer_ptr && tempInputPointer_ptr)
			{
				if (*(tempReturnPointer_ptr + j) != *(tempInputPointer_ptr + j)) // If the returned array doesn't match the expected array...
				{
					anyMismatches++; // ...indicate the mismatch and...
					break; // ...and stop looping
				}
			}
			else
			{
				if (tempReturnPointer_ptr != tempInputPointer_ptr)
				{
					anyMismatches++; // ...indicate the mismatch and...
					break; // ...and stop looping
				}
			}
		}

		/* Human-readable output */
		if (anyMismatches) // If there are any mismatches
		{
			printf("FAIL\n\t\t");
			if (tempInputPointer_ptr)
			{
				printf("\tExpected Value %d at Index[%d]\n\t\t", *(tempInputPointer_ptr + j), j);
			}
			else
			{
				printf("\tExpected a NULL pointer\n\t\t");
			}

			if (tempReturnPointer_ptr)
			{
				printf("\tReceived Value %d at Index[%d]\n", *(tempReturnPointer_ptr + j), j);
			}
			else
			{
				printf("\tReceived a NULL pointer\n");
			}

			free(tempReturnPointer_ptr);
		}
		else
		{
				printf("Pass\n");
				numOfTestsPassed++;
		}
		anyMismatches = 0; // Reset variable



		/* ERROR CODE TEST */
		numOfTestsRun++;

		/* Human-readable output */
		printf("\tError Code:\t");
		if (tempErrorCode == (*(inputArray + i))->expectedErrorCode)
		{
			printf("Pass\n");
			numOfTestsPassed++;
		}
		else
		{
			printf("FAIL\n\t\t");
			printf("\tExpected Error:\t%d\n\t\t", (*(inputArray + i))->expectedErrorCode);
			printf("\tReceived Error:\t%d\n", tempErrorCode);
		}
	}

	/* HUMAN READABLE TEST SUMMARY */
	if (numOfTestsRun) // If main() recorded some tests...
	{
		printf("\n\n%d tests were run.\n%d tests passed.\n\n", numOfTestsRun, numOfTestsPassed); // ...tell the user how they did
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
	int tempArrayDimension = 0;		// Variable which holds the calculated dimension of the int array to return

	if (!errorCode)					// If the int pointer is NULL...
	{
		return NULL;				// ...set the return value as NULL and...
	}
	if (startingNumber > endingNumber)	// If the start number is greater than the end number...
	{
		*errorCode = -2;				// ...set the return value as NULL and...
		return NULL;				// ...set the error code variable to -2
	}
	else // Otherwise, the parameters are fine (so far)
	{
		 // Compute the dimension of the int array to return
		tempArrayDimension = endingNumber - startingNumber + 1;

		/* Paranoid error check */
		if (tempArrayDimension > 1) // If the calculated dimension is valid...
		{
			returnValue_ptr = (int *)calloc(tempArrayDimension, sizeof(int)); // Dynamically allocate initialized memory into an appropriately sized int array

			/* Semi-Paranoid error check */
			if (returnValue_ptr) // If calloc actually returned a pointer to valid memory space...
			{
				/* ...initialize that int array with the appropriate values */
				for (int i = 0; i < tempArrayDimension; i++)
				{
					*(returnValue_ptr + i) = startingNumber + i;
				}
				*errorCode = 0;
				return returnValue_ptr;
			}
			else // Otherwise, calloc messed up so...
			{
				*errorCode = -3;	// ...set the error code to -3 (which should be a very rare occurrence)
				return NULL; // ...return NULL and...
				
			}
		}
	}
}
