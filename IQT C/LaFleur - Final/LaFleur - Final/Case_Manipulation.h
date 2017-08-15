#ifndef __CASE_MANIPULATION_H__
#define __CASE_MANIPULATION_H__

#ifndef NULL
#define NULL ((void*)0)
#endif /* NULL */

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
unsigned int chg_alpha_case(unsigned int letter);


////////////////////////////// FUNC 2 //////////////////////////////
// ARGUMENTS:
//		string_ptr - a pointer to a nul-terminated string
// PURPOSE:
//		Change the case of each alphabet letter in string using chg_alpha_case()
// RETURN:
//		If string_ptr is NULL, return NULL
//		Otherwise, return string_ptr
char * chg_string_case(char * string_ptr);


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
char * chg_starting_here(char * string_ptr, int start_here);

#endif  /* __CASE_MANIPULATION_H__ */
