#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "student_header.h"

int main()
{
	//variables
	int arr[] = { 5, 3, 1, 2, 4 };

	sort_int_array(arr, (sizeof(arr)/sizeof(arr[0])));

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}