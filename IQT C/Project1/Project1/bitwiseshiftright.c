#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	//variables
	uint32_t userInput = 0;
	uint32_t bitChecker = 0x01 << 31;
	int i = 0;

	printf("Enter a positive whole number less than 21 billion-ish.\n");
	fscanf(stdin, "%u%*c", &userInput);

	for (int i = 0; i < sizeof(userInput) * 8; i++)
	{
		fprintf(stdout, "%d", (userInput & (bitChecker >> i)) > 0);
	}
	printf("\n");

	return 0;
}