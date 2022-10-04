#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* previous;
};

void insertBeginning(node** start)
{
	int value;
	struct node* last = (*start)->previous;

	struct node* temp = new node;
	temp->data = value;

	temp->next = *start;
	temp->data = value;

	last->next = (*start)->previous = temp;
	*start = temp;
}

void insertMiddle(node** start)
{

}

void insertEnd(node** start)
{
	if(*start == NULL)
	{
		int value;
		struct node* temp = new node;
		temp->data = value;
		temp->next = temp->previous = temp;
		*start = temp;
		return;
	}
	int value;
	node* last = (*start)->previous;

	struct node* temp = new node;
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
	else if((*start)->next == *start)
	{
		delete* start;
		*start = NULL;
	}
	else 
	{
		node* temp = new node;
		temp = (*start)->next;
		temp->previous = (*start)->previous;
		((*start)->previous)->next = temp;
		delete* start;
		*start = temp;
	}
}

void deleteNodeMiddle(node** start)
{
}

void deleteNodeEnd(node** start)
{
	if(*start == NULL)
	{
		return;
	}
	else if((*start)->next == *start)
	{
		delete* start;
		*start = NULL;
	}
	else
	{
		node* temp = new node;
		temp = *start;
		
		while(temp->next != (*start))
		{
			temp = temp->next;
		}

		(temp->previous)->next = temp->next;
		(temp->next)->previous = temp->previous;
		delete temp;
	}
}

void search(node* start)
{
	if(start == NULL)
	{
	}
	int el;
	cout << "Enter the element you want to search (Only Integer): ";
	cin >> el;

	node* temp = start;
	
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

	} while (temp != start);

	if(count == 0)
	{
		cout << "\nThere is no such element in the list";
	}
}

bool isEmpty(node* start)
{
	if(start == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void display(node* start)
{
	node* temp = start;

	if(temp == start)
	{
		cout << "\n List is empty";
		return;
	}
	else
	{
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != start);
	}
	cout << temp->data << " ";
}

void reverse(node** start)
{
	if(*start == NULL)
	{
		return;
	}

	node* temp = *start;
	
	while(temp->next != *start)
	{
		node* tem = temp->next;

		temp->next = temp->previous;

		temp->previous = tem;

		temp = tem;
	}
	
	node* tem = temp->next;
	temp->next = temp->previous;
	temp->previous = tem;
	*start = temp;
}

void clear(node* start)
{
	if(start == NULL)
	{
		cout << "The list is empty";
		return;
	}

	while (start != NULL)
	{
		deleteNodeEnd(&start);
	}
}

void Menu()
{
	cout << "=============================================="
		"======================";
	cout << "\nMenu:\n";
	cout << "1. Insert from front\n";
	cout << "2. Insert from middle\n";
	cout << "3. Insert from the end\n";
	cout << "4. Insert Before Element\n";
	cout << "5. Delete From Front\n";
	cout << "6. Delete From End\n";
	cout << "7. Delete A Node\n";
	cout << "8. Search for a element\n";
	cout << "9. Reverse a the list\n";
	cout << "=============================================="
		"======================";
}

int main()
{
	int cho;
	char repeat_menu = 'y';

	node* start = NULL;
	Menu();
	do
	{
		cout << "\nEnter the number of the operation you wanna do:";
		cin >> cho;
		switch (cho)
		{
		case 1:
		{
			insertBeginning(&start);
			display(start);
			break;
		}
		case 2:
		{
			insertMiddle(&start);
			display(start);
			break;
		}
		case 3:
		{
			insertEnd(&start);
			display(start);
			break;
		}
		case 4:
		{
			deleteNodeBeginning(&start);
			display(start);
			break;
		}
		case 5:
		{
			deleteNodeMiddle(&start);
			display(start);
			break;
		}
		case 6:
		{
			deleteNodeEnd(&start);
			display(start);
			break;
		}
		case 7:
		{
			search(start);
			break;
		}
		case 8:
		{
			isEmpty(start);
			break;
		}
		case 9:
		{
			display(start);
			break;
		}
		case 10:
		{
			reverse(&start);
			display(start);
			break;
		}
		case 11:
		{
			clear(start);
			display(start);
			break;
		}
		default:
		{
			break;
		}
		}
	} while (repeat_menu == 'y' || repeat_menu == 'Y');
}