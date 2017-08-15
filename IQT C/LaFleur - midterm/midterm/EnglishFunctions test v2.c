/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// CAPSTONE LAB I.3.A-1 ///////////////////////////////////////////
////////////////////////////////////////////////// "Advanced String Theory" /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The requirement for this lab is to define all of the EnglishFunctions.h functions as declared.
// The comment blocks for each function should clearly indicate what the requirements are for the function.
// There are a variety of appropriate solutions for many of these functions.
// Unit Test Code v1.c has been written to test all of the functions both individually and as a whole.
// This header definition file includes the instructor solution for the header functions.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string.h>

/*
* FUNCTION:   int is_it_alphabet(signed char inputChar);
*
* ARGUMENTS:  inputChar is a single signed character that represents a single character
*                 that is tested as an alphabet letter.
*
* RETURNS:	  1 if inputChar is an alphabet character
*             0 if inputChar is not an alphabet character
*
* NOTES:      This function should not care if inputChar is uppercase or lowercase
*             The return value represents a boolean response without using a 'bool' data type
*             The letters a through z and A through Z represent "alphabet letters" for
*                 the purposes of this assignment.
*/
int is_it_alphabet(signed char inputChar)
{
	if (inputChar && ((inputChar >= 65 && inputChar <= 90) || (inputChar >= 97 && inputChar <= 122)))
	{
		return 1; //inputChar exists and is from 65 to 90 (A-Z) or 97 to 122 (a-z)
	}
	else
	{
		return 0; //inputChar is null or is not an alphabet character
	}
}


/*
* FUNCTION:   int remove_non_letters(char * sentenceString);
*
* ARGUMENTS:  sentenceString is expected to be a pointer to a null-terminated string
*
* RETURNS:	  Number of characters that were removed
*             -1 if senteceString is NULL
*
* NOTES:      The execution of this function must utilize is_it_alphabet() to determine
*                 whether or not a given char is an alphabet letter or not.
*             In addition to removing non-alphabet letters, this function will also remove any
*                 "blank space".
*             Most importantly, sentenceString will be null-terminated before the function returns
*/
int remove_non_letters(char * sentenceString)
{
	if (sentenceString)
	{
		int nonLettersCount = 0;
		int count = 0;

		for (int i = 0; i < strlen(sentenceString); i++)
		{
			if (!is_it_alphabet(sentenceString[i]))
			{
				nonLettersCount++;
			}
			else 
			{
				sentenceString[count] = sentenceString[i];
				count++;
			}
		}
		sentenceString[count] = '\0';
		return nonLettersCount;
	}
	else
	{
		return -1; //sentenceString is null
	}
}


/*
* FUNCTION:   int reverse_string(char * inputString, char * outputBuff, int inputPosition);
*
* ARGUMENTS:  inputString is expected to be a pointer to a null-terminated string
*             outputBuff is expected to be a pointer to a char array which will store the reversed string from inputString
*             inputPosition is the element of inputString that reverse_string() should reverse
*
* RETURNS:	  Number of characters that were reversed
*             -1 if either inputString or outputBuff is NULL
*             -2 if inputPosition is unrealistic
*                 Examples:
*                     inputPosition is negative
*                     inputPosition is out of the array's scope
*
* NOTES:      This function is recursive and, skipping over input validation, follows this algorithm:
*                 1. Reverse inputString[inputPosition] into outputBuff[]
*                 2. Call reverse_string() to reverse the next inputString[] position
*                 3. Count and return the total number of characters that were reversed from inputString[]
*                        into outputBuff[]
*             outputBuff is treated as the same length as inputString.  If outputBuff is longer, it
*                 will still be treated the same length as inputString.  Ideally, outputBuff and inputString
*                 are the exact same length.
*             Most importantly, outputBuff will be null-terminated before the function returns
*/
int reverse_string(char * inputString, char * outputBuff, int inputPosition)
{
	int numCharsReversed = 0;			// Default return value

	if (!inputString || !outputBuff)	// If either inputString or outputBuff have NULL pointers...
	{
		numCharsReversed = -1;			// ...that's a problem.
	}
	else								// Otherwise, proceed with...
	{
		int inputLength = strlen(inputString);	// Determine the length of inputString, a null-terminated string
		int outputLength = inputLength;			// Set the length of outputBuff the same as inputString

		if (inputPosition < 0 || outputLength <= inputPosition)	// If inputPosition is unrealistic...
		{
			numCharsReversed = -2;								// ...that's a problem.
		}
		else													// Otherwise, proceed with...
		{
			/*
			*  A single character at element inputString[inputPosition] is assigned to outputBuff.
			*  The element it's assigned to in outputBuff is chosen by subtracting inputPosition from
			*      the end of the outputBuff array.
			*/
			outputBuff[outputLength - 1 - inputPosition] = inputString[inputPosition];
			numCharsReversed++;									// One char has been assigned so the count is incremeneted
			if (inputPosition < (inputLength - 1))				// If this function has reached the last element of inputString...
			{
				/*
				*  ...then recursively call itself to reverse the next character in the string.
				*  The return value of the recursively called function collates to eventually
				*      become the final return value returned by the last reverse_string().
				*/
				numCharsReversed += reverse_string(inputString, outputBuff, (inputPosition + 1));
			}
		}
	}

	return numCharsReversed;
}


/*
* FUNCTION:   int clear_a_buffer(char * fullBuff, int buffSize);
*
* ARGUMENTS:  fullBuff is expected to be a pointer to a char array
*             buffSize represents the dimension of fullBuff[]
*
* RETURNS:	  0 on success
*             -1 if fullBuff is NULL
*             -2 if buffSize is unrealistic
*                 Examples:
*                     buffSize is zero
*                     buffSize is negative
*
* NOTES:      This function 'zeroizes' all of the elements of fullBuff[buffSize]
*             fullBuff does not necessarily need to be a null-terminated string since the array's
*                 dimension is passed in as an argument (for safety)
*/
int clear_a_buffer(char * fullBuff, int buffSize)
{
	if (fullBuff)
	{
		if (buffSize < 1)
		{
			return -2; //buffSize is zero or negative
		}

		for (int i = 0; i < buffSize; i++)
		{
			fullBuff[i] = 0;
		}

		return 0; //success
	}
	else
	{
		return -1; //fullBuff is null
	}
}

