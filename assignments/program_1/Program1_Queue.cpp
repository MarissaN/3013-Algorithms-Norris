
///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            Assignment 1 - Assorted Queue
// Files:            Program1_Queue.cpp
// Semester:         Advance Structures and Algorithms Spring 2018
//
// Author:           Marissa Norris
// Email:            rissanorris16@gmail.com
// Description:
//       This program enters randomly generated integers into a linked list in an ascending order
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>

using namespace std;

//Create a container for our list data
struct node {
	int data;
	node* next;
};

/**
* Class: intLinkedList
* Purpose:
*     Implements a singly linked list that holds integers.
* Methods:
*     void  orderedSert(int x)
*     node* find(int key)
*     node* remove(int key)
*     void  print()
*/
class intLinkedList
{
private:
	node* Head;
public:
	intLinkedList()
	{
		Head = NULL;
	}
	
	//Method: orderedSert()
	//Enters the value x into a node and places this node in the right location
	//to maintain ascending order
	void orderedSert(int x)
	{

		//empty list case
		if (!Head)
		{
			Head = new node;
			Head->data = x;
			Head->next = NULL;
		}
		//One item case
		else if (Head->next == NULL)
		{
			node*T = new node;
			//if the value to be entered is less than/equal to 
			//the current only value in the list
			if (Head->data >= x)
			{
			  //Places newly created node before the previous node
				T->data = x;
				T->next = Head;
				Head = T;
			}
			//if the node is greater than the current value already
			//in linked list
			else
			{
			  //Places the new node after the previous node
				T->data = x;
				T->next = NULL;
				Head->next = T;
			}
		}

		//not empty list and more than one value in the list
		else
		{
			node * T = new node;
			//Check first item in list if x is
			//less than/equal to the head node
			if (Head->data >= x)
			{
				//add x before head
				T->data = x;
				T->next = Head;
				Head = T;

			}
			else// if x is greater than the head then have to
			//traverse the list
			{
				T = Head;
				//while not at the end of the list and x is greater/equal to the
				//data in the ext node, keep travelling down the list
				while (T->next != NULL && (x >= T->next->data))
				{
					T = T->next;
				}

				if (T->next == NULL) //X will go to end
				{
					T->next = new node;
					T = T->next;
					T->data = x;
					T->next = NULL;
				}
				else //X is inserted in between some nodes in list
				{
					node*temp = new node;
					temp->data = x;
					temp->next = T->next;
					T->next = temp;
				}

			}
		}

	}
	
//Method: Find()
//uses variable key to find the desired node 
//and then returns the node or NULL if node not found
	node* Find(int key)
	{
		node* temp = Head;
		while (temp)
		{
			if (temp->data == key)
			{
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
	
//Method:Remove()
//with the key, the method finds the desired node
//the deletes it from the list
	void Remove(int key)
	{
		node* result = Find(key);
		if (result)
		{
			node* temp = Head;
			while (temp->next != result)
			{
				temp = temp->next;
			}
			temp->next = result->next;
			delete result;
		}
	}

//Method: print()
//prints the values in the list
	void print()
	{
		node* p = Head;
		while (p) {
			cout << p->data << endl;
			p = p->next;
		}
	}
};

int main()
{
	// seed random number generator
	srand(8734587);


	// declare instance of intLinkedList turning
	// a class definition into an "object"
	intLinkedList mylist;
	int ran;

	//Load 10 random ints into our list
	for (int i = 0; i<10; i++)
	{
		ran = rand() % 100;
		mylist.orderedSert(ran);
	}

	//print the list
	mylist.print();


	system("pause");
	return 0;
}