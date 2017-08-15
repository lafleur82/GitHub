#include <stdio.h>

int main()
{
	int input = 0;

	printf("Enter a char: ");

	input = getc(stdin);

	printf("Your char minus 1 is: ");
	putc(--input, stdout);
	printf("\n");

	getchar();
	return 0;
}
