#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

char separatedAlphabet[] = "a,b,c,d,e,f";
const char* correctAlphabet = "fedcba";

typedef struct _node {
	char letter;
	struct _node* next;
} node, *pnode;

typedef struct _list {
	pnode head;
} list, *plist;

size_t determineSize(char input[])
{
	size_t length = 0;
	int i = 0;

	while (input[i])
	{
		if (input[i] != ',')
		{
			length++;
		}
		i++;
	}

	return length;
}

// This method should create an empty list and return the list pointer with the head initialized
plist createList()
{
	plist nodeList = (plist)malloc(sizeof(plist));
	nodeList->head = NULL;

	return nodeList;
}

// This method should append a node *TO THE FRONT* of the list. Pay attention to the special case
// of when the list is empty
pnode appendNode(plist nodeList, char nodeData)
{
	pnode newNode = (pnode)malloc(sizeof(pnode));

	newNode->letter = nodeData;
	newNode->next = nodeList->head;
	nodeList->head = newNode;

	return newNode;
}

pnode insertNode(plist nodeList, char nodeData, int position)
{
	if (nodeList && nodeData && position)
	{
		pnode currentNode = nodeList->head;

		pnode newNode = (pnode)malloc(sizeof(pnode));
		newNode->letter = nodeData;

		for (int i = 0; i <= position; i++)
		{
			if (i == position)
			{
				if (currentNode->next)
				{
					newNode->next = currentNode->next;
				}
				currentNode->next = newNode;
				break;
			}

			currentNode = currentNode->next;
		}

		return newNode;
	}
}

char removeNode(plist nodeList, int position)
{
	pnode currentNode = nodeList->head;
	char data = { 0 };

	for (int i = 0; i <= position; i++)
	{
		if (i == position - 1)
		{
			if (currentNode->next->next)
			{
				free(currentNode->next);
				currentNode->next = currentNode->next->next;
			}
			else
			{
				free(currentNode->next);
				currentNode->next = NULL;
			}
		}

		currentNode = currentNode->next;
	}

	return data;
}

// Implement this last using the previous methods
pnode letterList(char input[])
{
	if (input)
	{
		int len = determineSize(input);
		if (len > 0)
		{
			plist nodeList = createList();
			for (int i = 0; i < len; i++)
			{
				if (input[i] != ',')
				{
					if (!nodeList->head || input[i] < nodeList->head->letter)
					{
						appendNode(nodeList, input[i]);
					}
					else
					{
						pnode currentNode = nodeList->head;
						int count = 0;

						while (currentNode->next)
						{
							if (input[i] > currentNode->letter)
							{
								count++;
							}
							else
							{
								insertNode(nodeList, input[i], count);
							}
							currentNode = currentNode->next;
						}
					}
				}
			}

			return nodeList->head;
		}
	}
}

int main()
{
	char string[] = "a,c,b";

	pnode list = letterList(string);
	getchar();
}