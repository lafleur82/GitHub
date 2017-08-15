#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main()
{
	//variables
	unsigned int first, second, third = 0;

	//loop until user quits
	while (1 == 1)
	{
		//accept two int inputs
		printf("Enter two different numbers: \n");
		scanf("%d%d", &first, &second);

		
		if (first == second) //check that the numbers are different
		{
			printf("Your numbers cannot be the same.\n");
		}
		else //determine which int is larger and assign that number to the third int
		{
			if (first > second)
			{
				third = first;
				first = 0;
			}
			else
			{
				third = second;
				second = 0;
			}
		}

		//output all three ints if their sum is greater than two
		if (first + second + third > 2)
		{
			printf("First number: %d\nSecond number: %d\nThird number: %d\n", first, second, third);
		}

		//manually clear the input stream because _flushall() is stupid
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);

		//break out of the loop on anything but 'y'
		printf("Continue? (y/n): ");
		if (getchar() != 'y')
		{
			break;
		}
	}
	return 0;
}