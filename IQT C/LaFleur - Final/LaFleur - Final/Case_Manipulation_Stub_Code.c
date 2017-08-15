#include "Case_Manipulation.h"

////////////////////////////////////////////////////////////////////
//////////////////////////// Stub Code /////////////////////////////
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
////////////////////////// IMPORTANT NOTE //////////////////////////
////////////////////////////////////////////////////////////////////
// You may not utilize and C Standard libraries in this header.
////////////////////////////////////////////////////////////////////

////////////////////////////// FUNC 1 //////////////////////////////
// ARGUMENTS:
//		letter - numerical representation of a single character
// PURPOSE:
//		Change the case of letter if it is in fact an alphabet letter
// RETURN:
//		If letter is a lower-case alphabet letter, return its upper-case
//		If letter is an upper-case alphabet letter, return its lower-case
//		If letter is not an alphabet letter, return letter

unsigned int chg_alpha_case(unsigned int letter)
{
	if (letter > 64 && letter < 91)
	{
		return letter + 32;
	}
	else if (letter > 96 && letter < 123)
	{
		return letter - 32;
	}
	else
	{
		return letter;
	}
}


////////////////////////////// FUNC 2 //////////////////////////////
// ARGUMENTS:
//		string_ptr - a pointer to a nul-terminated string
// PURPOSE:
//		Change the case of each alphabet letter in string using chg_alpha_case()
// RETURN:
//		If string_ptr is NULL, return NULL
//		Otherwise, return string_ptr

char * chg_string_case(char * string_ptr)
{
	if (!string_ptr)
	{
		return NULL;
	}
	else
	{
		int i = 0;
		char * ptr = string_ptr;

		while (*ptr != '\0')
		{
			*ptr = chg_alpha_case(*ptr);
			ptr++;
		}

		return string_ptr;
	}
}

////////////////////////////// FUNC 3 //////////////////////////////
// ARGUMENTS:
//		string_ptr - a pointer to a nul-terminated string
//		start_here - the index of the nul-terminated string to begin at (see: string_ptr)
// PURPOSE:
//		Starting at index "start_here" utilize chg_string_case() to change the case of...
//			...each alphabet letter in string_ptr
// RETURN:
//		If string_ptr is NULL, return NULL
//		If start_here is outside of the string, return NULL
//		Otherwise, return a pointer to index "start_here"

char * chg_starting_here(char * string_ptr, int start_here)
{
	
	if (!string_ptr)
	{
		return NULL;
	}
	else
	{
		int count = 0;
		char * ptr = string_ptr;

		while (*ptr != '\0')
		{
			ptr++;
			count++;
		}

		if (start_here >= count)
		{
			return NULL;
		}
		else
		{
			chg_string_case(string_ptr + start_here);

			return string_ptr + start_here;
		}
	}

}
