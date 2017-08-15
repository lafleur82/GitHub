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

int main(void)
{
	puts("You still need to write parallel arrays to test sorting_hat()"); // Remove this

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
