#pragma once
/****************************************

Define a struct in a header file

Ensure this struct:
		Can be ordered (see: primary key)
		Can be linked

*****************************************/


//structs
typedef struct Students
{
	char studentName[25];
	int studentNum; //primary key
	float GPA;
	struct Students * next;
} Students;


//function prototypes
Students * add_to_list(Students * myHeadNode, Students * addThisNode, int addItAtThisPosition, int * errorCode);
Students * createStudent();
void clearList(Students * myHeadNode);
int print_my_list(Students * myHeadNode);
