/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// PERFORMANCE LAB (I.5.A) 8 /////////////////////////////////////////////
///////////////////////////////////////////////// FUNCTION POINTERS /////////////////////////////////////////////////
/////////////////////////////////////////// "Every integer is bigger in Texas" //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Define each of the following function prototypes IAW their associated comment blocks:
//     int low_to_high_compare(int x, int y)
//     int high_to_low_compare(int x, int y)
//     int absolute_low_to_high_compare(int x, int y)
//     int absolute_high_to_low_compare(int x, int y)
// Write eight (8) tests for bubble_sort() (see: the comment block below), two tests for each of the function
//     prototypes listed above. 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>

#ifndef TRUE
#define TRUE ((int)1)
#endif

#ifndef FALSE
#define FALSE ((int)0)
#endif


//function declarations
int low_to_high_compare(int x, int y);				// Choice 1
int high_to_low_compare(int x, int y);				// Choice 2
int absolute_low_to_high_compare(int x, int y);		// Choice 3
int absolute_high_to_low_compare(int x, int y);		// Choice 4

int bubble_sort(int * arrayOfInts, int numOfElements, int(*compare_function)(int, int));


//Write eight tests for bubble_sort(), two tests for each of the function prototypes listed above.

int main(void)
{
	int successCount = 0;
	int failCount = 0;	
	int numElements[] = { 5, 5, 1, 3};
	int * functions[] = { &low_to_high_compare, &high_to_low_compare, &absolute_low_to_high_compare, &absolute_high_to_low_compare };

	int function1Returns[] = { 0, 2, -2, -1 };
	int function2Returns[] = { 10, 8, -2, -1 };
	int function3Returns[] = { 0, 4, -2, -1 };
	int function4Returns[] = { 10, 6, -2, -1 };
	int * expectedReturns[] = { &function1Returns, &function2Returns, &function3Returns, &function4Returns };


	for (int j = 0; j < sizeof(functions) / sizeof(functions[0]); j++) //number of functions in the functions array
	{
		//declare the testcases for each function passthrough
		int testcase1[] = { 1, 2, 3, 4, 5 }; //test a zero swap
		int testcase2[] = { 2, -6, 4, 3, 5 }; //tests negative numbers and the sort
		int testcases3[] = { -5 }; //test for unrealistic numElements
		int * testcases[] = { &testcase1, &testcase2, &testcases3, NULL }; // NULL is testing pointer errors

		for (int i = 0; i < sizeof(testcases) / sizeof(testcases[0][0]); i++) //number of testcases in the testcases array
		{
			//not debug
			if (bubble_sort(testcases[i], numElements[i], functions[j]) == expectedReturns[j][i])
			{
				printf("Test %d for function %d succeeded.\n", i + 1, j + 1);
				successCount++; //if bubble_sort was successful then increment successCount
			}
			else
			{
				printf("Test %d for function %d  failed.\n", i + 1, j + 1);
				failCount++; //if bubble_sort failed then increment failCount
			}
		}

	}
	printf("%d tests succeeded.\n", successCount);
	printf("%d tests failed.\n", failCount);

	getchar();
	return 0;
}


/*
* FUNCTION:   bubble_sort(int * arrayOfInts, int numOfElements, int(*compare_function)(int, int))
*
* ARGUMENTS:  arrayOfInts - a pointer to an array of integers
*             numOfElements - the dimension of the integer array found at the int pointer arrayOfInts
*              compare_function - a function pointer; This function should take two ints as parameters
*                 and return an int.  The expectation is that compare_function performs a comparison
*                 of the two ints and returns a boolean value.  This boolean value should represent
*                 whether or not the two ints should be swapped.  If the return value of compare_function
*                 is 1, then the two ints should be swapped in place.
*
* RETURNS:    The total number of int swaps that were made
*             0 if no swaps were made
*             -1 if any pointer is NULL
*             -2 if numOfElements is unrealistic
*             -3 on any other error
*
* NOTES:      This function is already defined below.  Do not modify this function.
*             This function will sort, in place, the first "numOfElements" elements that are found
*                 in the integer array found at pointer "arrayOfInts".  To accomplish this, bubble_sort()
*                 will utilize the comparison function found at "compare_function" to accomplish this.
*                 The expectation is that compare_function will compare two ints, n1 and n2.  In this, it
*                 is expected that n1 comes before n2.  If n1 needs to swap with n2, compare_function will
*                 return 1.  If not, compare_function will return 0.  Any other return value from
*                 compare_function will be considered an error value (see: RETURNS).
*/


int bubble_sort(int * arrayOfInts, int numOfElements, int(*compare_function)(int, int))
{
	int i = 0;				// Iterating variable
	int j = 0;				// Iterating variable
	int swapCount = 0;		// Number of element swaps that have been made

	if (!arrayOfInts || !compare_function)	// If either of the pointers are NULL
	{
		return -1;	// return -1
	}
	else if (numOfElements < 2) // If the number of elements is unrealistic
	{
		return -2; // return -2
	}
	else
	{
		for (i = 0; i < numOfElements; i++) // Iterate through all of the elements
		{
			for (j = 0; j < (numOfElements - 1); j++) // comparing each element to all the other elements
			{
				if ((compare_function(*(arrayOfInts + j), *(arrayOfInts + j + 1))) > 0) // If the compare function suggests a swap...
				{
					// swap the values stored in each element
					*(arrayOfInts + j) = *(arrayOfInts + j) ^ *(arrayOfInts + j + 1);
					*(arrayOfInts + j + 1) = *(arrayOfInts + j) ^ *(arrayOfInts + j + 1);
					*(arrayOfInts + j) = *(arrayOfInts + j) ^ *(arrayOfInts + j + 1);
					swapCount++; // A swap took place so increment the number of swaps counted
				}
			}
		}
		return swapCount; // Return the total number of swaps that took place
	}

	return -3; //default return of -3 means there was an error
}


/*
 * FUNCTION:   low_to_high_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 * RETURNS:	   If x is greater than or equal to y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If x is greater than or equal y, y needs to be "bubbled up" to the top
 *             Large numbers are ordered first
 *
 * EXAMPLES:   x = 9, y = 0, return 1
 *             x = 8, y = 68, return 0
 *             x = -24, y = 318, return 0
 *             x = -318, y = -688, return 1
 */


int low_to_high_compare(int x, int y)
{
	if (x >= y)
	{
		return 1;
	}
	else if( y > x)
	{
		return 0;
	}
	else
	{
		return -1; //something weird happened...
	}
}


/*
 * FUNCTION:   int high_to_low_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 * RETURNS:	   If x is less than or equal to y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If x is less than or equal y, y needs to be "bubbled up" to the top
 *             Large numbers are ordered first
 * 
 * EXAMPLES:   x = 9, y = 0, return 0
 *             x = 8, y = 68, return 1
 *             x = -24, y = 318, return 1
 *             x = -318, y = -688, return 0
 */


int high_to_low_compare(int x, int y)
{
	if (x <= y)
	{
		return 1;
	}
	else if (y < x)
	{
		return 0;
	}
	else
	{
		return -1; //something weird happened...
	}
}


/*
 * FUNCTION:   int absolute_low_to_high_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 *  RETURNS:   If the absolute value of x is greater than or equal to the absolute value of y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If the absolute value of x is greater than or equal the absolute value of y,
 *                 y needs to be "bubbled up" to the top
 *             This function will not attempt to modify the values of x and y
 *             Smaller numbers, regardless of 'sign', are ordered first
 *
 * EXAMPLES:   x = 9, y = 0, return 1
 *             x = 8, y = 68, return 0
 *             x = -24, y = 318, return 0
 *             x = -318, y = -688, return 0
 */


int absolute_low_to_high_compare(int x, int y)
{
	if (abs(x) >= abs(y))
	{
		return 1;
	}
	else if (abs(y) > abs(x))
	{
		return 0;
	}
	else
	{
		return -1; //something weird happened...
	}
}


/*
 * FUNCTION:   absolute_high_to_low_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 * RETURNS:    If the absolute value of x is less than or equal to the absolute value of y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If the absolute value of x is less than or equal the absolute value of y,
 *                 y needs to be "bubbled up" to the top
 *             This function will not attempt to modify the values of x and y
 *             Large numbers, regardless of 'sign', are ordered first
 *
 * EXAMPLES:   x = 9, y = 0, return 0
 *             x = 8, y = 68, return 1
 *             x = -24, y = 318, return 1
 *             x = -318, y = -688, return 1
 */


int absolute_high_to_low_compare(int x, int y)
{
	if (abs(x) <= abs(y))
	{
		return 1;
	}
	else if (abs(y) < abs(x))
	{
		return 0;
	}
	else
	{
		return -1; //something weird happened...
	}
}
