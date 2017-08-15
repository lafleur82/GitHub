#include <stdio.h>

int main()
{
	char header1[] = { "Header1" };
	char header2[] = { "Header2" };
	char header3[] = { "Header3" };
	char header4[] = { "Header4" };
	int ints[] = { 1234, 4321, 5678, 8765 };
	char chars[] = { 65, 66, 67, 68 };
	int ints2[] = { 9876, 8765, 7654, 6543 };
	float floats[] = { 1.234, 2.345, 3.456, 4.567 };

	printf("%-12s%-12s%12s%12s\n", header1, header2, header3, header4);
	
	//loop for adding dashes
	for (int i = 0; i < 48; i++)
	{
		putchar('-');
	}
	printf("\n");
	
	printf("%-+12d%-12c%012d%12.3f\n", ints[0], chars[0], ints2[0], floats[0]);
	printf("%-+12d%-12c%012d%12.3f\n", ints[1], chars[1], ints2[1], floats[1]);
	printf("%-+12d%-12c%012d%12.3f\n", ints[2], chars[2], ints2[2], floats[2]);
	printf("%-+12d%-12c%012d%12.3f\n", ints[3], chars[3], ints2[3], floats[3]);


	return 0;
}