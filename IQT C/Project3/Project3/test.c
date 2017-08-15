#include <stdio.h>

main()
{
	char string[] = { "\n" };

	char * string_ptr = &string;

	printf("%d", strlen(string_ptr));

	getchar();
}