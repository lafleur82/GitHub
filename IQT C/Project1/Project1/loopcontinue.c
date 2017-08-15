#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//variables
	unsigned int x;
	int i;
	int count;

	//loop until user quits
	do
	{
		//initialize variables
		x = 0;
		i = 0;
		count = 0;

		printf("Enter a whole number (999 to exit)\n");
		scanf("%d", &x);
		if (x > 999)
		{
			break;
		}

		while (count < 20)
		{
			if (i == 0)
			{
				i++;
				continue;
			}

			if (x % i == 0 && x / i > 0)
			{
				printf("%d\n", i);

				if (x == i)
				{
					break;
				}

				count++;
			}

			i++;
		}

	} while (x < 1000);

	return 0;
}