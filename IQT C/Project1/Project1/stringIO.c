#include <stdio.h>

int main()
{
	while (1 == 1)
	{
		char buff[10];
		printf("Enter a string: ");
		fgets(buff, sizeof(buff), stdin);

		printf("You entered: ");
		fputs(buff, stdout);
		printf("\n");

		printf("Continue? ");
		if (getchar() != 10)
		{
			break;
		}	
	}
	return 0;
}