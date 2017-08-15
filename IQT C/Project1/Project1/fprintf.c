#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c = 0; // a, b, and c of the quadratic formula
	double pos, neg = 0.0;

	printf("Enter three numbers: ");
	scanf("%d%d%d", &a, &b, &c);
	printf("\n");

	if ((a > 0) && (((b*b) - (4*a*c)) > 0)) //must be greater than zero
	{
		pos = (-b + sqrt((b * b) - 4*a*c)) / (2 * a);
		neg = (-b - sqrt((b * b) - 4*a*c)) / (2 * a);
		printf("Positive: %g\nNegative: %g\n", pos, neg);
	}
	else if(a <= 0)
	{
		printf("First number must be greater than zero.\n");
	}
	else if((b*b) - (4*a*c) <= 0)
	{
		printf("B^2 - 4ac must be greater than zero.\n");
	}
	else
	{
		printf("Not sure what happened there...\n");
	}
}