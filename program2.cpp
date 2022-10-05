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
	/*creates a new node named tempand gives it the value that the user gave*/
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
		/*creates a nodeand gives it the previous of start
		which the end of the list since it's a 
		doubly circular linkedlist 
		(Basically makes it the end node of the list)*/
		node* end = *start;
		end = end->previous;

		//temp's next now points at the start
		temp->next = end->next;
		//temp's previous now poinrs to the old end
		temp->previous = end;
		//start now points to the new end
		(end->next)->previous = temp;
		//old end now points to the new end
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
		/*if there is only one node (start) then it deletes it
		and gives the start NULL value since there is nothing 
		in the list*/
		delete* start;
		*start = NULL;
	}
	else 
	{
		//creates a new node with the name temp
		node* temp = new node;
		//temp is the copy of the 2nd node
		temp = (*start)->next;
		//temp's previous is the end
		temp->previous = (*start)->previous;
		//end's next is now temp (2nd node/new start)
		((*start)->previous)->next = temp;
		//deletes the old start
		delete* start;
		//start has the values and information of 2nd node so it's the new start
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
		cout << "\nNothing to delete\n";
		return;
	}
	else if((*start)->next == *start)
	{
		/*if there is only one node (start) then it deletes it
		and gives the start NULL value since there is nothing
		in the list*/
		delete* start;
		*start = NULL;
	}
	else
	{
		node* temp = new node;
		temp = *start;
		
		//temp is now the end of the list
		temp = temp->previous;
		//node before the last node's next is now the start
		(temp->previous)->next = temp->next;
		//start's previous is now the node before the last node
		(temp->next)->previous = temp->previous;
		//deletes temp node
		delete temp;
	}
}

void search(node* start)
{
	if(start == NULL)
	{
		cout << "\nThe List is empty\n";
		return;
	}
	int el, pos = 0, count = 0;
	cout << "Enter the element you want to search (Only Integer): ";
	cin >> el;

	node* temp = start;
	/*While temp node isn't equal to the start it compares the data with the
	value the user typed (it ignores the while statement first time it's doing that's why it works)*/
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
	
	/*until it reaches the end node it keeps repeating 
	this operation*/
	while(temp->next != *start)
	{
		//creates a second node and makes it 2nd node
		node* tem = temp->next;
		//makes next of temp point to previous of temp
		temp->next = temp->previous;
		//Previous of temp now points to it's next
		temp->previous = tem;
		//moves to the next node
		temp = tem;
	}
	/*For updating the old last node*/
	node* tem = temp->next;
	temp->next = temp->previous;
	temp->previous = tem;
	//makes the old last the new head
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
		free(*start);
		*start = NULL;
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
	cout << "Note: Please use ONLY integers\n";
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
			cout << "\nThere is no such operation\n";
			Menu();
			break;
		}
		}
		cout << "\nContinue?(Y/N)";
		cin >> repeat_menu;

	} while (repeat_menu == 'y' || repeat_menu == 'Y');
	return 0;
}