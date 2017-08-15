#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

float swap_temp(float temp, char CorF);

int main()
{
	//variables
	float temperature = 0.0;
	char CorF = 0;

	printf("Enter a temperature and the current measurement type to be converted: \n(i.e. 98.7 F)\n");
	scanf("%f%*c%c", &temperature, &CorF);

	if (swap_temp(temperature, CorF) == -1001)
	{
		printf("Temperature is below max known range.\n");
	}
	else if (swap_temp(temperature, CorF) == -1000)
	{
		printf("Unknown measurement type.\n");
	}
	else if (swap_temp(temperature, CorF) > -1000)
	{
		printf("%.2f converted from %c is %.2f\n", temperature, CorF, swap_temp(temperature, CorF));
	}
	else
	{
		printf("Unknown error.\n");
	}

	getchar();
	return 0;
}

float swap_temp(float temp, char CorF)
{
	if ((temp > -460 && (CorF == 'f' || CorF == 'F')) || (temp > -274 && (CorF == 'c' || CorF == 'C')))
	{
		if (CorF == 'c' || CorF == 'C')
		{
			return temp * 9.0 / 5.0 + 32.0;
		}
		else if (CorF == 'f' || CorF == 'F')
		{
			return (temp - 32.0) * 5.0 / 9.0;
		}
		else
		{
			return -1000;
		}
	}
	else
	{
		return -1001;
	}
}