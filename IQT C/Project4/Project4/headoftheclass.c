#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main()
{
	int myError = 0;
	MyStruct * headNode = NULL; // will contain the head node of the linked list
	MyStruct * tempHeadNode = NULL; //test add_a_struct on this

	MyStruct student1 = { "Arntz", 1, 90.0, NULL };
	MyStruct student2 = { "Bean", 2, 98.0, NULL };
	MyStruct student3 = { "Bivins", 3, 93.0, NULL };
	MyStruct student4 = { "Calderon", 4, 92.0, NULL };
	MyStruct student5 = { "Hernandez", 5, 86.0, NULL };
	MyStruct student6 = { "Isbell", 6, 91.0, NULL };
	MyStruct student7 = { "Kopel", 7, 95.0, NULL };
	MyStruct student8 = { "LaFleur", 8, 97.0, NULL };
	MyStruct student9 = { "Petty", 9, 94.0, NULL };
	MyStruct student10 = { "Pearson", 10, 100.0, NULL };
	MyStruct student11 = { "Scott", 11, 100.0, NULL };
	MyStruct student12 = { "Shinn", 12, 97.0, NULL };
	MyStruct student13 = { "Smith", 13, 96.0, NULL };
	MyStruct student14 = { "Stone", 14, 93.0, NULL };
	MyStruct student15 = { "Tamo", 15, 93.0, NULL };
	
	MyStruct * students[] = {
		&student1, &student2, &student3, &student4,
		&student5, &student6, &student7, &student8,
		&student9, &student10, &student11, &student12,
		&student13, &student14, &student15 };

	// print structs if link_my_strucs doesn't return an error
	
	if ((myError = link_my_structs(students, (sizeof(students) / sizeof(*students)))) == 0)
	{
		headNode = &student1;
		print_my_structs(headNode);
	}
	else if (myError == -1)
	{
		printf("Students pointer was null.\n");
	}
	else if (myError = -2)
	{
		printf("Not enough nodes to link. (At least 2 required)\n");
	}
	else
	{
		printf("Unknown error.\n");
	}
	printf("\n\n");
	myError = 0; //reset myError

	// not in the initial linked list
	MyStruct student16 = { "McKay", 16, 97.0, NULL };

	if (headNode = add_a_struct(headNode, &student16, 8, &myError))
	{
		print_my_structs(headNode);
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

	getchar();
	return 0;
}


/**********************************************************************************

Return value –	Struct pointer to the ‘head’ node
				NULL on any error

Parameters –	myHeadNode – A pointer to the head node of a linked list of MyStruct variables
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

MyStruct * add_a_struct(MyStruct * myHeadNode, MyStruct * addThisNode, int addItAtThisPosition, int * errorCode)
{
	if (!errorCode)
	{
		// no errorCode location to store error
		return NULL; //exit immediately
	}
	else if (!myHeadNode)
	{
		*errorCode = -1; // myHeadNode is null
	}
	else if (!myHeadNode->next)
	{
		*errorCode = -2; // myHeadNode not part of a linked list
	}
	else if (!addThisNode)
	{
		*errorCode = -4; // no node to add
	}
	else if (!addItAtThisPosition)
	{
		*errorCode = -5; // position doesn't exist
	}
	else
	{
		int successCode = 0;
		int i = 0;

		if (addItAtThisPosition == 0) //updating the headnode
		{
			addThisNode->next = myHeadNode;
			myHeadNode = addThisNode;
			successCode = 1;
		}
		else
		{
			MyStruct * currentNode = myHeadNode;

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
					addThisNode->previous = currentNode;		// set previous for the new node to the memory location of the current node
					currentNode->next->previous = addThisNode;	// update previous for node after new node
					
					successCode = 1;
					break;
				}

				currentNode = currentNode->next;
			}
		}

		if (successCode)
		{
			return myHeadNode; // return the original head node
		}
		else
		{
			*errorCode = -6; // addItAtThisPosition didn't exist in the linked list
			return NULL;
		}
	}

	*errorCode = -3; // catch-all error
	return NULL;
}


/**************************************************************

Return value –	The number of nodes in the linked list
				-1 if myHeadNode is NULL
				-2 if myHeadNode is not part of a linked list
				-3 for all other errors

Parameters –	myHeadNode – A pointer to the head node of a 
				linked list of MyStruct variables

Purpose –		Print the structs in a human-readable format

***************************************************************/

int print_my_structs(MyStruct * myHeadNode)
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


/*********************************************************

Return value:	0 on success
				-1 if myArray is NULL
				-2 if numOfNodes is unlinkable (less than 2)
				-3 for all other errors

Parameters:		myArray – An array of MyStruct pointers…
				numOfNodes – …of this dimension

Purpose – Link the structs, in place, found in the array

**********************************************************/

int link_my_structs(MyStruct ** myArray, int numOfNodes)
{
	if (!myArray)
	{
		return -1; // myArray is null
	}
	else if (numOfNodes < 2)
	{
		return -2; // numOfNodes is less than 2
	}
	else
	{
		for (int i = 0; i < numOfNodes - 1; i++)
		{
			// last node shouldn't have a next
			if (i != numOfNodes)
			{
				(*(myArray + i))->next = *(myArray + i + 1);
			}

			// first node shouldn't have a previous
			if (i != 0)
			{
				(*(myArray + i))->previous = *(myArray + i - 1);
			}
		}
		
		return 0; // return 0 for success
	}

	return -3; // catch-all error
}
