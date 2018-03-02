///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            Assignment 3 - Crazy words
// Files:            Main.cpp
//					 avlTree.h
//					 BSTree.h
//					 avlTree.cpp
//					 BSTree.cpp
//					 adjectives.txt
//					 adverbs.txt
//					 animals.txt
//					 nouns.txt
//					 verbs.txt
//					 tenthousandwords.txt
// Semester:         Advance Structures and Algorithms Spring 2018
//
// Author:           Marissa Norris
// Email:            rissanorris16@gmail.com
// Description:
//      generate about 10000 names, we are going to compare the performance of a Binary Search Tree 
//      vs an AVL tree when it comes to finding those named components in each tree
/////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//Struct created for left and right leaves of tree
struct node
{
	string data;
	string type;
	node *left;
	node *right;
	node()
	{
		data = "";
		type = "";
		left = NULL;
		right = NULL;
	}
	node(string w, string t)
	{
		data = w;
		type = t;
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
*		node * search(node *&root, string key)
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
	int numAdj;
	int numAdv;
	int numNou;
	int numVeb;
	int sum;
	//Counts how many leaves in tree
	int count(node *root);
	//Inserts a new node into the tree
	void insert(node *&root, node *&temp);
	//Prints whats in the tree
	void print_node(node *n, string label = " ");
	/**
	* type = ['predecessor','successor']
	*/
	//Finds the smallest value(last leaf in the tree) on the left
	//side or right side
	node *minValueNode(node *root);
	//Delets node from tree
	node *deleteNode(node *&root, string key);
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
	void setAdj(int Adj);
	int getAdj();

	void setAdv(int Adv);
	int getAdv();

	void setNou(int Nou);
	int getNou();

	void setVeb(int Veb);
	int getVeb();
	void setSum(int S);
	int getSum();
	bool search( string key);
	void FinalSearch(string x, string y);
	//int searchCount(string key, int sum, int AdjS, int AdvS, int NouS, int VebS);
	void searchCount(string key);
	//Calls private method funtion insert
	void insert(string x, string y);
	//Calls private method function deleteNode
	void deleteNode(string key);
	//Calls private method function minValueNode
	void minValue();
	//Finds the height
	int height(string key = " ");
	//Returns data in node if not pointing to null
	string top();
	/* Function to line by line print level order traversal a tree*/
	void printLevelOrder();
	void GraphVizOut(string filename);
};
