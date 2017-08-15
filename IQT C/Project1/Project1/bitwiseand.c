#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	const uint8_t red = 1, orange = 2, yellow = 4, green = 8, 
		blue = 16, indigo = 32, violet = 64, ultraviolet = 128;
	uint8_t color = 0;

	while (1 == 1)
	{
		printf("Enter a number from 1-255: ");
		_flushall();
		scanf("%"SCNu8, &color);
		printf("\n");

		printf("Your word:   %"PRIu8"\n", color);
		printf("Red:         %d \n", (color & red) > 0);
		printf("Orange:      %d \n", (color & orange) > 0);
		printf("Yellow:      %d \n", (color & yellow) > 0);
		printf("Green:       %d \n", (color & green) > 0);
		printf("Blue:        %d \n", (color & blue) > 0);
		printf("Indigo:      %d \n", (color & indigo) > 0);
		printf("Biolet:      %d \n", (color & violet) > 0);
		printf("Ultraviolet: %d \n\n", (color & ultraviolet) > 0);
		
		getchar();
		printf("Continue? (y/n):");
		if (getchar() == 'n')
		{
			break;
		}
		
	}
	return 0;
}