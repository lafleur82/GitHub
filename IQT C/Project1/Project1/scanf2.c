#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main()
{
	int num1 = 0;
	int num2 = 0;
	char symbol = 0;

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
			printf("The result of %d divided by %d is %g. \n", num1, num2, (float) num1 / num2);
			break;
		default:
			break;
		}

		getchar();
		printf("Another? (y/n): \n");
		if (getchar() == 'n')
		{
			break;
		}
	}
}