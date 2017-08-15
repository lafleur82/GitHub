#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

#define MAX_SEL_LENGTH 6 		//maximum size of the user input 
#define CMD_PREFIX 3 			//size of the first [0:3] chars in a command, used to determine the correct type of command (-ins or -del)

/*
C Programming - Evaluation Exam 
This is a doubly linked-list intended to assess the examinee's capabilities with loops, if-else conditions, functions, pointers, and dynamic memory
Fill in the functions that have been left incomplete.
Be sure to correctly handle the pointers when inserting and deleting from the list.
Be sure to test the -insp and -dell linked-list operations with values of 0 and the # of nodes in the list.

Good luck!!
*/		


int main(void)
{
	char selection[MAX_SEL_LENGTH] = "-loop";	//arbitrary value, just to keep the loop going until valid input is received
	int pos = 0;
	struct Node* newNode = NULL;			
	
	while(strncmp(selection, "-exit", MAX_SEL_LENGTH) != 0)
	{
		printf("\nLinked list commands (-help for list of commands): ");
		scanf("%s", selection);
		
		if(strncmp(selection, "-help", MAX_SEL_LENGTH) == 0)
		{
			printf("\nInsert at head of list: -insh");
			printf("\nInsert at tail of list: -inst");
			printf("\nInsert at position: -insp");
			printf("\nPrint list: -prnt");
			printf("\nPrint list reverse: -prnr");
			printf("\nDelete from list: -dell");
			printf("\nExit: -exit");
		}
		
		else if(strncmp(selection, "-ins", CMD_PREFIX ) == 0)	//check the first 3 characters 
		{
			newNode = CreateNewNode();				
			
			if(newNode)
			{
				//last character determines the correct insert function to call
				if(selection[4] == 'h')			
				{
					InsertNodeAtHead(newNode);
				}
				
				else if(selection[4] == 't')
				{
					InsertNodeAtTail(newNode);
				}
				
				else if(selection[4] == 'p')
				{
					printf("\npos: ");
					scanf("%d", &pos);		
					
					if(pos >= 0)
					{
						InsertNodeAtPosition(newNode, pos);
					}
					
					else
					{
						printf("\nError: invalid position entered");
					}
				}
			}
			
			else
			{
				printf("\nError encountered when creating new node");
			}
		}
		
		else if(strncmp(selection, "-prn", CMD_PREFIX) == 0)
		{

			if(selection[4] == 't')
			{
				PrintList();
			}
				
			else if (selection[4] == 'r')
			{
				PrintReverse();
			}
		}
		
		else if(strncmp(selection, "-dell", MAX_SEL_LENGTH) == 0)
		{
			printf("\npos: ");
			scanf("%d", &pos);
			
			if(pos >= 0)
			{
				DeleteAtPosition(pos);
			}
				
			else
			{
				printf("Error: invalid position entered");
			}
			
		}
		
	}
	
	CleanUpList();
	
	return 0;
}

//INPUT: Get string input from the user
//PROCESS: Create a new node from user input, allocate memory
//RETURN: Pointer to the new node

struct Node* CreateNewNode()
{
	struct Node * newNode = (struct Node*) calloc(1, sizeof(struct Node));

	printf("Insert string to be stored. (Max %d characters)\n", MAX_STR_LENGTH);
	getchar();
	scanf("%[1-9A-Za-z., ]", &newNode->string);
	
	return newNode;
}


//INPUT: A valid Node pointer
//PROCESS: The Node pointer is inserted at the head of the list

void InsertNodeAtHead(struct Node* node)
{
	if (node)
	{
		if (!headNode)					//if empty list, headNode AND tailNode pointers assigned to the node
		{
			headNode = node;
			tailNode = node;
		}
		else							//headNode pointer is assigned to the new node
		{
			node->next = headNode;
			headNode->previous = node;
			headNode = node;
		}

		nodeCount++;
	}
}


//INPUT: A valid Node pointer
//PROCESS: The Node pointer is inserted at the tail of the list


void InsertNodeAtTail(struct Node* node)
{
	if (node)
	{
		if (!headNode && !tailNode)		//if empty list, headNode AND tailNode pointers assigned to the node
		{
			InsertNodeAtHead(node);
		}
		else							//tailNode pointer is assigned to the new node
		{
			node->previous = tailNode;
			tailNode->next = node;
			tailNode = node;
			nodeCount++;
		}
	}
}


//INPUT: A valid Node pointer, position to place in the linked list
//PROCESS: The Node pointer is inserted at the specified position
//Nodes are properly linked to the new node

void InsertNodeAtPosition(struct Node* node, int pos)
{
	if (node && pos)
	{
		if (headNode && tailNode)
		{
			if (pos < nodeCount)
			{
				struct Node * currentNode = headNode;

				//get to the right position
				for (int i = 1; i < pos; i++)
				{
					currentNode = currentNode->next;
				}

				node->previous = currentNode;
				node->next = currentNode->next;
				currentNode->next->previous = node;
				currentNode->next = node;

				nodeCount++;
			}
		}
		else
		{
			printf("Head and tail must be declared first.\n");
		}
	}
}

 
//INPUT: None
//PROCESS: Traverse the list, print every node string in order
//if empty list, display an error message to screen

void PrintList()
{
	if (headNode)
	{
		struct Node * currentNode = headNode;

		while (currentNode)
		{
			printf("%s\n", currentNode->string);
			currentNode = currentNode->next;
		}
	}
}


//INPUT: None
//PROCESS: Traverse the list, print every node string in reverse order
//if empty list, display an error message to screen
//RETURN: none

void PrintReverse()
{
	if (tailNode)
	{
		struct Node * currentNode = tailNode;

		while (currentNode)
		{
			printf("%s\n", currentNode->string);
			currentNode = currentNode->previous;
		}
	}
}


//INPUT: integer position
//PROCESS: Traverse the list, delete node specified by position, reconnect list 
//RETURN: None

void DeleteAtPosition(int pos)
{
	if (pos && pos <= nodeCount)
	{
		struct Node * currentNode = headNode;

		if (pos == 1) // if pos == 1 then we are deleting the head
		{
			if (headNode->next == tailNode)
			{
				headNode = tailNode;
				headNode->next = NULL;
			}
			else
			{
				headNode = currentNode->next;
			}

			free(currentNode);
			nodeCount--;
		}
		else if (pos == nodeCount) // if pos == nodeCount then we are deleting the tail
		{
			currentNode = tailNode; 

			if (headNode->next == tailNode)
			{
				tailNode = headNode;
				headNode->next = NULL;
			}
			else
			{
				tailNode = currentNode->previous;
			}

			free(currentNode);
			nodeCount--;
		}
		else if (pos > 1 && pos < nodeCount)
		{
			//get to the right position
			for (int i = 1; i < pos; i++)
			{
				currentNode = currentNode->next;
			}

			currentNode->previous->next = currentNode->next;
			currentNode->next->previous = currentNode->previous;

			free(currentNode);
			nodeCount--;
		}
		else
		{
			printf("Nothing to delete.\n");
		}
	}
}


void CleanUpList()
{
	
	struct Node* travNode = headNode;
	struct Node* delNode;
	
	if(nodeCount > 0 && travNode != NULL)
	{
		while(travNode != NULL)
		{
			delNode = travNode;
			travNode = travNode->next;
			free(delNode);
			
		}
		
		nodeCount = 0;
	}
}


//Is the linkedList empty (1 if empty, 0 if not)
int IsEmpty()
{
	if (headNode)
		return 0;
	else
		return 1;
}