#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>


int main()
{
	//variables
	float num1 = 0.0;
	float num2 = 0.0;
	int errNum = 0;
	
	printf("Enter two numbers to be divided: ");
	scanf("%f%*%f", &num1, &num2);
	printf("\n");

	assert(num2);
	printf("%d divided by %d is: %", num1, num2, num1 / num2);

	getchar();
	getchar();
	return 0;
}
