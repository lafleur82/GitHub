/***********************
**   Capstone Lab     **
**  Blivins, Stone,   **
** Hernandez, LaFleur **
***********************/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <inttypes.h>

int main()
{
	//variables
	uint32_t arbitraryInt = 255;
	uint32_t userInput = 0;
	uint32_t bitMask = 0x01;

	printf("Enter a number between 0 and %d. \n", (sizeof(userInput) * 8) - 1);
	scanf("%u", &userInput);

	printf("%u\n", arbitraryInt ^ (bitMask << userInput));

	printf("Original binary:\n%u\n", arbitraryInt);
	for (int i = 0; i < sizeof(userInput) * 8; i++)
	{
		printf("%d", (arbitraryInt & ((bitMask << 31) >> i)) > 0);
	}
	printf("\n\n");

	printf("Bitmasked binary:\n%u\n", arbitraryInt ^ (bitMask << userInput));
	for (int i = 0; i < sizeof(userInput) * 8; i++)
	{
		printf("%d", ((arbitraryInt ^ (bitMask << userInput)) & ((bitMask << 31) >> i)) > 0);
	}
	printf("\n");
	
	getchar();
	getchar();
	return 0;
}