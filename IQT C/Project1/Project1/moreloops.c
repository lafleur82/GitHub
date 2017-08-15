#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//variables
	int n, i = 0;
	char c = 0;

	printf("Enter a max number.");
	scanf("%d%*c", &n);

	printf("a: Print all even numbers up to your max.\nb: Print all odd numbers.\n");
	scanf("%c%*c", &c);

	if (c == 'a')
	{
		while (i <= n)
		{
			if (!(i % 2))
			{
				printf("%d\n", i);
			}
			i++;
		}
	}
	else if (c == 'b')
	{
		for (i = 0; i <= n; i++)
		{
			if (i % 2)
			{
				printf("%d\n", i);
			}
		}
	}
	else
	{
		printf("Invalid entry.\n");
	}

	return 0;
}