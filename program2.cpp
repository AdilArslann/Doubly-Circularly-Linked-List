#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* previous;
};

void insertBeginning(struct Node** start, int value)
{
	struct Node* last = (*start)->prevoius;

	struct Node* temp = new Node;
	temp->data = value;

	temp->next = *start;
	temp->data = value;

	last->next = (*start)->previous = temp;
	*start = temp;
}

void insertMiddle(struct Node** start)
{

}
void insertEnd(struct Node** start, int value)
{
	if(*start == NULL)
	{
		struct Node* temp = new Node;
		temp->data = value;
		temp->next = temp->previous = temp;
		*start = temp;
		return;
	}

	Node* last = (*start)->previous;

	struct Node* temp = new Node;
	temp->data = value;

	temp->next = *start;

	(*start)->previous = temp;

	temp->previous = last;
	last->next = temp;
}