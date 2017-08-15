#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//variables
	int num1 = 0;
	int num2 = 0;
	char symbol = 0;

	//loop until user quits
	while (1 == 1)
	{
		printf("Enter two integers, separated by a math operator to be performed.\n (i.e. 3*4) \n");
		scanf("%d%c%d", &num1, &symbol, &num2);

		switch (symbol)
		{
		case '+':
			printf("The result of %d plus by %d is %d. \n", num1, num2, num1 + num2);
			break;
		case '-':
			printf("The result of %d minus by %d is %d. \n", num1, num2, num1 - num2);
			break;
		case '*':
			printf("The result of %d multiplied by %d is %d. \n", num1, num2, num1 * num2);
			break;
		case '/':
			if (num2)
			{
				printf("The result of %d divided by %d is %g. \n", num1, num2, (float)num1 / num2);
			}
			break;
		default:
			printf("Error: unexpected input.\n");
			break;
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