#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* previous;
};

void insertBeginning(node** start, int value)
{
	struct Node* last = (*start)->prevoius;

	struct Node* temp = new Node;
	temp->data = value;

	temp->next = *start;
	temp->data = value;

	last->next = (*start)->previous = temp;
	*start = temp;
}

void insertMiddle(node** start)
{

}
void insertEnd(node** start, int value)
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

void deleteNodeBeginning(node** start)
{
	if(*start == NULL)
	{
		return;
	}
	else if((*head)->next == *head)
	{
		delete* head;
		*head = NULL;
	}
	else 
	{
		node* temp = new node;
		temp = (*head)->next;
		temp->previous = (*head)->previous;
		((*head)->previous)->next = temp;
		delete* head;
		*head = temp;
	}
}

void deleteNodeMiddle()
{
}

void deleteNodeEnd(node** head)
{
	if(*head == NULL)
	{
		return;
	}
	else if((*head)->next == *head)
	{
		delete* head;
		*head = NULL;
	}
	else
	{
		node* temp = new node;
		temp = *head;
		
		while(temp->next != (*head))
		{
			temp = temp->next;
		}

		(temp->previous)->next = temp->next;
		(temp->next)->previous = temp->previous;
		delete temp;
	}
}

void search(node* head)
{
	if(head == Null)
	{
	}
	int el;
	cout << "Enter the element you want to search (Only Integer): ";
	cin >> el;

	node* temp = head;
	
	int pos=0, count=0;
	do
	{
		if(temp->data == el)
		{
			cout << "\nElement found at postion:" << pos + 1;
			count++;
		}
		pos++;
		temp = temp->next;

	} while (temp != head);

	if(count == 0)
	{
		cout << "\nThere is no such element in the list";
	}
}

bool isEmpty(node* head)
{
	if(head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void display(node* head)
{
	struct Node* temp = head;

	while(temp-> != start)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << " ";
}

void reverse(node* head)