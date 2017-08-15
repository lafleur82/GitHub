#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Automobile
{
	int numDoors;
	int numCylinders;
	int year;
	char * make;
	char * model;
	char * color;
	struct Automobile * next;
};
int maxed(int num1, int num2);

int main()
{
	struct Automobile * head;
	struct Automobile * current;

	struct Automobile myCar1 = { 4,4, 2016, "Subaru", "Forester", "blue" };
	struct Automobile myCar2 = { 4,4, 2015, "Subaru", "Impreza", "black" };
	struct Automobile myCar3 = { 4,4, 2014, "Honda", "CRV", "green" };

	myCar1.next = &myCar2;
	myCar2.next = &myCar3;

	head = &myCar1;

	current = head;
	
	while (current)
	{
		printf("Make: %s and model: %s\n", current->make, current->model);
		current = current->next;
	}

	getchar();
	return 0;
}

int maxed(int num1, int num2)
{
	int rtn = 0;

	if (num1 > num2)
	{
		rtn = num1;
	}
	else
	{
		rtn = num2;
	}

	return rtn;
}