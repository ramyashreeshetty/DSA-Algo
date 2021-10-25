// C++ program to return first node of loop.
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Node;

Node * newNode(int data)
{
    Node * newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->link=NULL;
    return newnode;
}


// Function to detect and remove loop
// in a linked list that may contain loop
Node* detectAndRemoveLoop(Node* head)
{
	// If list is empty or has only one node
	// without loop
	if (head == NULL || head->link == NULL)
		return NULL;

	Node *slow = head, *fast = head;

	// Move slow and fast 1 and 2 steps
	// ahead respectively.
	slow = slow->link;
	fast = fast->link->link;

	// Search for loop using slow and
	// fast pointers
	while (fast && fast->link) {
		if (slow == fast)
			break;
		slow = slow->link;
		fast = fast->link->link;
	}

	// If loop does not exist
	if (slow != fast)
		return NULL;

	// If loop exists. Start slow from
	// head and fast from meeting point.
	slow = head;
	while (slow != fast) {
		slow = slow->link;
		fast = fast->link;
	}

	return slow;
}

/* Driver program to test above function*/
int main()
{
	Node* head = newNode(50);
	head->link = newNode(20);
	head->link->link = newNode(15);
	head->link->link->link = newNode(4);
	head->link->link->link->link = newNode(10);

	/* Create a loop for testing */
	head->link->link->link->link->link = head->link->link;
    //50-20-(15->4->10->)

	struct node * res = detectAndRemoveLoop(head);
	if (res == NULL)
		printf("Loop does not exist");
	else
		printf("Loop starting node is %d",res->data);

	return 0;
}
