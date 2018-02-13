
///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            Assignment 2 - Binary Tree
// Files:            Main.cpp
//                   BSTree.cpp
//                   BSTree.h
// Semester:         Advance Structures and Algorithms Spring 2018
//
// Author:           Marissa Norris
// Email:            rissanorris16@gmail.com
// Description:
//      
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BSTree.h "

using namespace std;

int main()
{
	srand(2342);

	BSTree B;

	//Inserts values to tree
	B.insert(38);
	B.insert(10);
	B.insert(29);
	B.insert(27);
	B.insert(5);
	B.insert(43);
	B.insert(36);
	B.insert(3);
	B.printLevelOrder();
	B.GraphVizOut("before.txt");

	//Removes values from tree
	 while(B.top())
	 {
	     cout<<"removing: "<<B.top()<<endl;
		
	    B.deleteNode(B.top());
	 }

	B.deleteNode(3);
	B.deleteNode(29);
	B.deleteNode(27);
	B.deleteNode(10);
	B.printLevelOrder();

	B.GraphVizOut("after.txt");
	system("pause");
	return 0;
}