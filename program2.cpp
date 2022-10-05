#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* previous;
};

void insertBeginning(node** start)
{
	cout << "\nEnter the value:";
	//creates a new node named temp
	node* temp = new node;
	cin >> temp->data;
	if (*start == NULL)
	{
		/*If the list is empty it creates a node pointing
		to itself and makes it the start*/
		temp->next = temp;
		temp->previous = temp;
		*start = temp;
	}
	else
	{
		//new node will point to the old start (it becomes the new start)
		temp->next = *start;

		//previous of the old start (end) will now be previous of new start.
		temp->previous = (*start)->previous;
		
		//end will now point to the new node(start)
		((*start)->previous)->next = temp;

		//old start's previous will now point to the new start
		(*start)->previous = temp;

		//makes the new node start of the list
		*start = temp;
	}
}

void insertMiddle(node** start)
{

}

void insertEnd(node** start)
{
	cout << "\nEnter the value:";

	node* temp = new node;
	cin >> temp->data;

	if(*start == NULL)
	{
		/*If the list is empty it creates a node pointing
		to itself and makes it the start*/
		temp->next = temp;
		temp->previous = temp;
		*start = temp;
	}
	else
	{
		node* end = *start;
		end = end->previous;

		temp->next = end->next;
		temp->previous = end;
		(end->next)->previous = temp;
		end->next = temp;
	}
}

void deleteNodeBeginning(node** start)
{
	if(*start == NULL)
	{
		cout << "\nNothing to delete\n";
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

void isEmpty(node* start)
{
	if(start == NULL)
	{
		cout << "\nYes, the list is empty\n";
	}
	else
	{
		cout << "\nNo, the list isn't empty\n";
	}
}

void display(node* start)
{
	node* current = start;
	if (current == NULL)
	{
		cout << "\nThe List is empty";
	}
	else 
	{
		do 
		{
			cout << current->data << " ";
			current = current->next;
		} while (current != start);
	}
}

void reverse(node** start)
{
	if(*start == NULL)
	{
		cout << "\nNothing to reverse\n";
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

void clear(node** start)
{
	if(*start == NULL)
	{
		cout << "The list is empty";
		return;
	}
	else
	{
		/*creates two nodes and the 'current' node 
		points to the 2nd node*/
		node* temp, * current;
		current = (*start)->next;

		/*While the current node isn't equal to the start
		deletes the current node and moves on the next one
		by giving the information to the temp*/
		while(current != *start)
		{
			temp = current->next;
			free(current);
			current = temp;
		}

		//Deletes the start and gives it value: NULL
		free(start);
		start = NULL;
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
	cout << "4. Delete from front\n";
	cout << "5. Delete from middle\n";
	cout << "6. Delete from end\n";
	cout << "7. Search a element\n";
	cout << "8. Check if the list is empty\n";
	cout << "9. Print the list\n";
	cout << "10. Reverse the whole list\n";
	cout << "11. Clear the list\n";
	cout << "=============================================="
		"======================";
}

int main()
{
	int choice;
	char repeat_menu = 'y';

	// Declaration of head node
	node* start = NULL;
	Menu();
	do {
		cout << "\nEnter Your Choice:";
		cin >> choice;
		switch (choice) {
		case 1: {
			insertBeginning(&start);
			display(start);
			break;
		}
		case 2: {
			insertMiddle(&start);
			display(start);
			break;
		}
		case 3: {
			insertEnd(&start);
			display(start);
			break;
		}
		case 4: {
			deleteNodeBeginning(&start);
			display(start);
			break;
		}
		case 5: {
			deleteNodeMiddle(&start);
			display(start);
			break;
		}
		case 6: {
			deleteNodeEnd(&start);
			display(start);
			break;
		}
		case 7: {
			search(start);
			break;
		}
		case 8: {
			isEmpty(start);
			break;
		}
		case 9: {
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
			clear(&start);
			display(start);
			break;
		}
		default: 
		{
			cout << "\nWrong Choice!!!";
			Menu();
			break;
		}
		}
		cout << "\nEnter More(Y/N)";
		cin >> repeat_menu;

	} while (repeat_menu == 'y' || repeat_menu == 'Y');
	return 0;
}