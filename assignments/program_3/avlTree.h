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

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

struct Anode
{
	string value;
	string name;
	Anode *left;
	Anode *right;
	Anode *parent;
	int avlValue;
    Anode(string word, string type){
        value = word;
		name = type;
        left = right = parent = NULL;
        avlValue = 0;
    }
};

/**
* Class: avlTree
* Purpose:
*      to create the funtions and variables of AVL tree
* Methods:
*		bool rightHeavy(Anode *)
*		bool leftHeavy(Anode *)
*		void insert(Anode *&, Anode *&)
*		void inorder(Anode *)
*		void preorder(Anode *)
*		void postorder(Anode *)
*		Anode* remove(Anode*& , string )
*	    Anode* predSuccessor(Anode*)
*	    void printNode(Anode *, string )
*		int  height(Anode *)
*		void computeAvlValues(Anode *&)
*		void rotateLeft(Anode *&)
*		void rotateRight(Anode *&)
*		int  avlValue(Anode *)
*		avlTree()
*		~avlTree()
*		void setAdj(int Adj)
*		int getAdj()
*		void setAdv(int Adv)
*		int getAdv()
*		void setNou(int Nou)
*		int getNou()
*		void setVeb(int Veb)
*		int getVeb()
*		void setSum(int S)
*		int getSum()
*		void print()
*		void doDumpTree(Anode *)
*		void dumpTree()
*		doDumpTree(root)
*		void insert(string, string)
*		void showInorder(){inorder(root)
*		void showPreorder(){preorder(root)
*		void showPostorder(){postorder(root)
*		bool search(string)
*		void searchCount(string)
*		void remove(string word){root = remove(root,word)
*		int  treeHeight()
*		void graphVizGetIds(Anode *,ofstream &)
*		void graphVizMakeConnections(Anode *,ofstream &)
*		void graphVizOut(string )
*/
class avlTree{

private:
	Anode *root;
	int numAdj;
	int numAdv;
	int numNou;
	int numVeb;
	int sum;
	bool rightHeavy(Anode *);
	bool leftHeavy(Anode *);
	void insert(Anode *&, Anode *&);
	void inorder(Anode *);
	void preorder(Anode *);
	void postorder(Anode *);
	Anode* remove(Anode*& , string );
    Anode* predSuccessor(Anode*);
    void printNode(Anode *, string );
	int  height(Anode *);
	void computeAvlValues(Anode *&);
	void rotateLeft(Anode *&);
	void rotateRight(Anode *&);
	int  avlValue(Anode *);

public:
	avlTree();
	~avlTree();
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
	void print();
	void doDumpTree(Anode *);
	void dumpTree(){cout<<"---------------------------------"<<endl;
	                cout<<"Root:   "<<root<<"\n";
					doDumpTree(root);
	};
	void insert(string, string);
	void showInorder(){inorder(root);};
	void showPreorder(){preorder(root);};
	void showPostorder(){postorder(root);};
	bool search(string);
	void searchCount(string);
	void remove(string word){root = remove(root,word);};
	int  treeHeight();
    void graphVizGetIds(Anode *,ofstream &);
	void graphVizMakeConnections(Anode *,ofstream &);
	void graphVizOut(string );
};

