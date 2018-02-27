//Marissa Norris
//Assignment 4 - Binary Tree
//BSTree.h
//BSTree definition file

#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//Struct created for left and right leaves of tree
struct node
{
	int data;
	node *left;
	node *right;
	node()
	{
		data = -1;
		left = NULL;
		right = NULL;
	}
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

/**
* Class: BSTree
* Purpose:
*      to create the funtions and variables of Binary Tree
* Methods:
*		int count(node *root)
*		void insert(node *&root, node *&temp)
*		void print_node(node *n, string label)
*		node *minValueNode(node *root)
*		node *deleteNode(node *&root, int key)
*		int height(node *root)
*		void printGivenLevel(node *root, int level)
*		void GraphVizGetIds(node *nodePtr, ofstream &VizOut)
*		void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut)
*		BSTree()
*		~BSTree()
*		int count()
*		void insert(int x)
*		void deleteNode(int key)
*		void minValue()
*		int height(int key)
*		int top()
*		void printLevelOrder()
*		void GraphVizOut(string filename)
*/
class BSTree
{
private:

	//The first node in the tree
	node * root;
	//Counts how many leaves in tree
	int count(node *root);
	//Inserts a new node into the tree
	void insert(node *&root, node *&temp);
	//Prints whats in the tree
	void print_node(node *n, string label);
	/**
	* type = ['predecessor','successor']
	*/
	//Finds the smallest value(last leaf in the tree) on the left
	//side or right side
	node *minValueNode(node *root);
	//Delets node from tree
	node *deleteNode(node *&root, int key);
	//Calculates the height of tree
	int height(node *root);
	/* Print nodes at a given level */
	void printGivenLevel(node *root, int level);

	//Used for webgraphviz
	void GraphVizGetIds(node *nodePtr, ofstream &VizOut);
	void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut);

public:
	//Default Constructor
	BSTree();
	//Default deconstructor
	~BSTree();
	//Calls private method function count
	int count();
	//Calls private method funtion insert
	void insert(int x);
	//Calls private method function deleteNode
	void deleteNode(int key);
	//Calls private method function minValueNode
	void minValue();
	//Finds the height
	int height(int key);
	//Returns data in node if not pointing to null
	int top();
	/* Function to line by line print level order traversal a tree*/
	void printLevelOrder();
	void GraphVizOut(string filename);
};
