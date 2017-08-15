#include <stdio.h>

#ifdef EOF
#undef EOF
#endif

#define EOF 66
#define FOPEN_MAX 64
#define FILENAME_MAX 256
//#define DEBUG

#if defined(DEBUG) && !defined(_INC_STDIO)

#else
#define PRINT_MACRO(x) printf(#x " is: %d\n", x)
#endif

int main(void)
{
#ifndef DEBUG
	PRINT_MACRO(FOPEN_MAX);
	PRINT_MACRO(FILENAME_MAX);
	PRINT_MACRO(EOF);
#endif // !DEBUG
	return 0;
}