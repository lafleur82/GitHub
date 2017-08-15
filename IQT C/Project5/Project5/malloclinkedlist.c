#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main()
{
	int myError = 0;
	int myPos = 0;
	Students * headNode = NULL; // will contain the head node of the linked list

	printf("Add a student to linked list? (y/n): \n");

	while (getchar() == 'y')
	{
		printf("What position number?: ");
		scanf("%d", &myPos);
		headNode = add_to_list(headNode, createStudent(), myPos, &myError);

		if (headNode)
		{
			printf("Student added.\n");
		}
		else if (myError == -1)
		{
			printf("Head node was null.\n");
		}
		else if (myError = -2)
		{
			printf("Not enough nodes to link. (At least 2 required)\n");
		}
		else if (myError = -4)
		{
			printf("addThisNode is NULL\n");
		}
		else if (myError == -5)
		{
			printf("addItAtThisPosition is NULL.\n");
		}
		else if (myError = -6)
		{
			printf("addItAtThisPosition didn't exist in the linked list.\n");
		}
		else
		{
			printf("Unknown error.");
		}

		printf("Another? (y/n)");
		getchar();
	}

	if (headNode)
	{
		printf("%d students printed.\n", print_my_list(headNode));
	}

	getchar();
	getchar();

	clearList(headNode); //free the memory
	return 0;
}


/**********************************************************************************

Return value –	Struct pointer to the ‘head’ node
				NULL on any error

Parameters –	myHeadNode – A pointer to the head node of a linked list of Students variables
				addThisNode – A pointer to a struct variable to insert
				addItAtThisPosition – Insert the stuct before this node
				errorCode – An integer pointer to store error codes

Error Codes –	-1 if myHeadNode is NULL
				-2 if myHeadNode is not part of a linked list
				-3 for all other errors
				-4 addThisNode is NULL
				-5 addItAtThisPosition is NULL
				-6 addItAtThisPosition didn't exist in the linked list

Purpose –		Insert a struct as a new node to a linked list

***********************************************************************************/

Students * add_to_list(Students * myHeadNode, Students * addThisNode, int addItAtThisPosition, int * errorCode)
{
	if (!errorCode)
	{
		// no errorCode location to store error
		//exit immediately
	}
	else if (!addItAtThisPosition)
	{
		*errorCode = -5; // position doesn't exist
	}
	else if (!myHeadNode && addItAtThisPosition == 1)
	{
		// if myHeadNode is null and addItAtThisPosition is 1 then addThisNode is the head node for new linked list
		return addThisNode;
	}
	else if (!myHeadNode)
	{
		*errorCode = -1; // myHeadNode is null
	}
	else if (!myHeadNode->next && !addItAtThisPosition == 1)
	{
		*errorCode = -2; // myHeadNode not part of a linked list
	}
	else if (!addThisNode)
	{
		*errorCode = -4; // no node to add
	}
	else
	{
		int successCode = 0;
		int i = 0;

		if (addItAtThisPosition == 0) //updating the headnode
		{
			addThisNode->next = myHeadNode;
			return addThisNode;
		}
		else
		{
			Students * currentNode = myHeadNode;

			for (i = 1; i <= addItAtThisPosition; i++)
			{
				if (i == addItAtThisPosition)
				{
					// update next for the new node if current node has a next value
					if (currentNode->next)
					{
						addThisNode->next = currentNode->next;
					}

					currentNode->next = addThisNode;			// set next for currentNode to the memory location of the new node
					
					return myHeadNode;
				}

				currentNode = currentNode->next;
			}
		}

		*errorCode = -6; // addItAtThisPosition didn't exist in the linked list
	}

	if (errorCode && !*errorCode)
	{
		*errorCode = -3; // catch-all error
	}
	return NULL;
}


/**********************************************************************

Return value -  pointer to new Student struct to be added to linked list

Parameters -	None

Purpose -		Prompt user for inputs to create a new struct
***********************************************************************/

Students * createStudent()
{
	Students * student = calloc(1, sizeof(Students));

	printf("Enter last name: \n");
	scanf("%s", &student->studentName);

	printf("Enter list position: \n");
	scanf("%d", &student->studentNum);

	printf("Enter student GPA: \n");
	scanf("%f", &student->GPA);

	student->next = NULL;

	return student;
}


/**********************************************************************

Return value -  none

Parameters -	pointer to head node

Purpose -		free memory of linked list nodes
***********************************************************************/

void clearList(Students * myHeadNode)
{
	Students * nextNode = myHeadNode;

	while (nextNode)
	{
		nextNode = myHeadNode->next;
		free(myHeadNode);
		myHeadNode = nextNode;
	}
}


/**************************************************************

Return value –	The number of nodes in the linked list
				-1 if myHeadNode is NULL
				-2 if myHeadNode is not part of a linked list
				-3 for all other errors

Parameters –	myHeadNode – A pointer to the head node of a 
				linked list of Students variables

Purpose –		Print the structs in a human-readable format

***************************************************************/

int print_my_list(Students * myHeadNode)
{
	if (!myHeadNode)
	{
		return -1; // myHeadNode is null
	}
	else if (!myHeadNode->next)
	{
		return -2; // not a linked list
	}
	else
	{
		int count = 0;
		
		while (myHeadNode)
		{
			count++;
			printf("%s, student number: %d, has a GPA of %.2f.\n", myHeadNode->studentName, myHeadNode->studentNum, myHeadNode->GPA);
			myHeadNode = myHeadNode->next;
		}

		return count;
	}

	return -3; // catch-all return for errors...
}
