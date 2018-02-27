//Marissa Norris
//Program 2 - Binary Tree
//BSTree.cpp
//implementaion file

#include "BSTree.h "
#include <fstream>

using namespace std;

/**
* Function: count 
* Purpose:
*     count number of nodes in tree
* Output:
*    integer number of sum
*/
int BSTree:: count(node *root)
{
	if (!root)
	{
		return 0;
	}
	else
	{
		return 1 + count(root->left) + count(root->right);
	}
}

/**
* Function: insert
* Purpose:
*		inserts new node into the tree
* Output:
*		none
*/
void BSTree::insert(node *&root, node *&temp)
{
	if (!root)//if no root
	{
		//make new value root
		root = temp;
	}
	else//place value in the right place in the tree
	{
		if (temp->data < root->data)
		{
			insert(root->left, temp);
		}
		else
		{
			insert(root->right, temp);
		}
	}
}

/**
* Function: print_node
* Purpose:
*		prints organized recording of the nodes data
* Output:
*		none
*/
void BSTree::print_node(node *n, string label = "")
{
	if (label != "")
	{
		cout << "[" << label << "]";
	}
	cout << "[[" << n << "][" << n->data << "]]\n";
	if (n->left)
	{
		cout << "\t|-->[L][[" << n->left << "][" << n->left->data << "]]\n";
	}
	else
	{
		cout << "\t\\-->[L][null]\n";
	}
	if (n->right)
	{
		cout << "\t\\-->[R][[" << n->right << "][" << n->right->data << "]]\n";
	}
	else
	{
		cout << "\t\\-->[R][null]\n";
	}
}

/**
* Function: minValueNode
* Purpose:
*		traverses the tree till find the smallest node on the left
*		sub tree or right sub tree
* Output:
*		returns the found node
*/
node * BSTree::minValueNode(node *root)
{
	node *current = root;
	//if the right node is being used
	if (root->right)
	{
		current = root->right;
		while (current->left != NULL)
		{
			//traverse tree
			current = current->left;
		}
	}
	//if the left node is being used
	else if (root->left)
	{
		current = root->left;
		while (current->right != NULL)
		{
			current = current->right;
		}
	}

	return current;
}

/**
* Function: deleteNode
* Purpose:
*		deletes the node with the data matching the key
* Output:
*		returns the temp value to replace the previous node
*/
node * BSTree::deleteNode(node *&root, int key)
{
	//if tree is empty
	if (!root)
	{
		return NULL;
	}
	//if the key is lesser than root node data
	if (key < root->data)
	{
		//travels to left of tree
		cout << "going left" << endl;
		root->left = deleteNode(root->left, key);
	}
	//if key is greater than root node data
	else if (key > root->data)
	{
		//travels to right of tree
		cout << "going right" << endl;
		root->right = deleteNode(root->right, key);
	}
	else
	{	//if at the last node on the left side of tree
		if (root->left == NULL)
		{
			//deletes the found node the returns the value
			//to replace it
			node *temp = root->right;
			delete root;
			return temp;
		}
		//if at the last node on the right side of tree
		else if (root->right == NULL)
		{
			node *temp = root->left;
			delete root;
			return temp;
		}

		
			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			node *temp = minValueNode(root);

			print_node(temp, "minvaluenode");

			// Copy the inorder successor's content to this node
			root->data = temp->data; 
		
			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->data);
			
	}
	return root;
}

/**
* Function: height
* Purpose:
*		calculates the height of the tree
* Output:
*		the calculated height
*/
int BSTree:: height(node *root)
{
	if (!root)//if there is no tree
	{
		return 0;
	}
	else
	{	//calculates the height by using recurstion
		int left = height(root->left);
		int right = height(root->right);
		if (left > right)
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}

/**
* Function: printGivenLevel
* Purpose:
*		prints values in tree from top level to last level
* Output:
*		none
*/
void BSTree:: printGivenLevel(node *root, int level)
{
	if (root == NULL)//if empty tree
		return;
	if (level == 1)//if only one value in tree
	{
		print_node(root);
	}
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

//************************************************************************
// Method to help create GraphViz code so the expression tree can
// be visualized. This method prints out all the unique node id's
// by traversing the tree.
// Recivies a node pointer to root and performs a simple recursive
// tree traversal.
//************************************************************************
void BSTree::GraphVizGetIds(node *nodePtr, ofstream &VizOut)
{
	static int NullCount = 0;
	if (nodePtr)
	{
		GraphVizGetIds(nodePtr->left, VizOut);
		VizOut << "node" << nodePtr->data
			<< "[label=\"" << nodePtr->data << "\\n"
			//<<"Add:"<<nodePtr<<"\\n"
			//<<"Par:"<<nodePtr->parent<<"\\n"
			//<<"Rt:"<<nodePtr->right<<"\\n"
			//<<"Lt:"<<nodePtr->left<<"\\n"
			<< "\"]" << endl;
		if (!nodePtr->left)
		{
			NullCount++;
			VizOut << "nnode" << NullCount << "[label=\"X\",shape=point,width=.15]" << endl;
		}
		GraphVizGetIds(nodePtr->right, VizOut);
		if (!nodePtr->right)
		{
			NullCount++;
			VizOut << "nnode" << NullCount << "[label=\"X\",shape=point,width=.15]" << endl;
		}
	}
}

//************************************************************************
// This method is partnered with the above method, but on this pass it
// writes out the actual data from each node.
// Don't worry about what this method and the above method do, just
// use the output as your told:)
//************************************************************************
void BSTree:: GraphVizMakeConnections(node *nodePtr, ofstream &VizOut)
{
	static int NullCount = 0;
	if (nodePtr)
	{
		GraphVizMakeConnections(nodePtr->left, VizOut);
		if (nodePtr->left)
			VizOut << "node" << nodePtr->data << "->"
			<< "node" << nodePtr->left->data << endl;
		else
		{
			NullCount++;
			VizOut << "node" << nodePtr->data << "->"
				<< "nnode" << NullCount << endl;
		}

		if (nodePtr->right)
			VizOut << "node" << nodePtr->data << "->"
			<< "node" << nodePtr->right->data << endl;
		else
		{
			NullCount++;
			VizOut << "node" << nodePtr->data << "->"
				<< "nnode" << NullCount << endl;
		}

		GraphVizMakeConnections(nodePtr->right, VizOut);
	}
}

/**
* Function: BSTree
* Purpose:
*		default constructor
* Output:
*		none
*/
BSTree::BSTree()
{
	root = NULL;
}

/**
* Function: ~BSTree
* Purpose:
*		deconstructor
* Output:
*		none
*/
BSTree::~BSTree()
{
}

/**
* Function: count
* Purpose:
*		calls the private funtion count with the tree root
* Output:
*		value returned from private funtion
*/
int BSTree:: count()
{
	return count(root);
}

/**
* Function:	instert
* Purpose:
*		inserts new node x to tree by calling the
*		private method insert
* Output:
*
*/
void BSTree::insert(int x)
{
	node *temp = new node(x);
	insert(root, temp);
}

/**
* Function: deleteNode
* Purpose:
*		deletes the node with data that matches the key by calling
*		the private method deleteNode
* Output:
*		none
*/
void BSTree::deleteNode(int key)
{	//returns temp value from deleteNode to the  root value
	root = deleteNode(root, key);
}

/**
* Function: minValue
* Purpose:
*		calls print_node function with the parameters being the
*		the private method function of minValueNode
* Output:
*		none
*/
void BSTree::minValue()
{
	print_node(minValueNode(root), "minVal");
}

/**
* Function: height
* Purpose:
*		returns value from calling function height with the 
*		parameter of root if the key is less than 0
* Output:
*		the value returned from function call
*/
int BSTree::height(int key = -1)
{
	if (key > 0)
	{
		//find node
	}
	else
	{
		return height(root);
	}
	return 0;
}

/**
* Function: BSTree
* Purpose:
*		goes to the top of the tree
* Output:
*		the value of the node is returned
*/
int BSTree::top()
{
	if (root)
		return root->data;
	else
		return 0;
}

/**
* Function: printLevelOrder
* Purpose:
*		Function to line by line print level order traversal a tree
* Output:
*		none
*/
void BSTree:: printLevelOrder()
{
	cout << "Begin Level Order===================\n";
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
	{
		printGivenLevel(root, i);
		cout << "\n";
	}
	cout << "End Level Order===================\n";
}

//************************************************************************
// Recieves a filename to place the GraphViz data into.
// It then calls the above two graphviz methods to create a data file
// that can be used to visualize your expression tree.
//************************************************************************
void BSTree::GraphVizOut(string filename)
{
	ofstream VizOut;
	VizOut.open(filename);
	VizOut << "Digraph G {\n";
	GraphVizGetIds(root, VizOut);
	GraphVizMakeConnections(root, VizOut);
	VizOut << "}\n";
	VizOut.close();
}
