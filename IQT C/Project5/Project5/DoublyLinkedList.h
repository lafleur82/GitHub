
#define MAX_STR_LENGTH  20

//Definiton of a Node, which comprise the (doubly) linked list
struct Node
{
	char string[MAX_STR_LENGTH]; 
	struct Node* next;
	struct Node* previous;
};

//Number of nodes in the linked list
int nodeCount = 0;

//Start of the linked list. Always keep track of the head pointer
struct Node* headNode;

//Tail of the linked list. 
struct Node* tailNode;

struct Node* CreateNewNode();													//Create new node should ask for user input 
void InsertNodeAtHead(struct Node* node);										//Insert node at the start of the list
void InsertNodeAtPosition(struct Node* node, int pos);							//Insert node at the position index specified 
void InsertNodeAtTail(struct Node* node);										//Insert node at the end of the list
void PrintList();																//Traverse list and print contents of each node
void PrintReverse();															//Traverse the list in reverse and print contents of each node
void DeleteAtPosition(int pos);													//Delete node at position index specified
void CleanUpList();																//Deallocate memory for entire list
int IsEmpty();																	//Is the linkedList empty (1 if empty, 0 if not)
