#pragma once
/****************************************

Define a struct in a header file

Ensure this struct:
		Can be ordered (see: primary key)
		Can be linked

*****************************************/


//structs
typedef struct MyStruct
{
	char studentName[25];
	int studentNum; //primary key
	float GPA;
	struct MyStruct * next;
	struct MyStruct * previous;
} MyStruct;


//function prototypes
int link_my_structs(MyStruct ** myArray, int numOfNodes);
int print_my_structs(MyStruct * myHeadNode);
MyStruct * add_a_struct(MyStruct * myHeadNode, MyStruct * addThisNode, int addItAtThisPosition, int * errorCode);
