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
#include <vector>
#include<cstdlib>
#include "BSTree.h"
#include "avlTree.h"

using namespace std;

//prototypes
void LoadTree(string FileName, string type, avlTree &Atree, BSTree &Btree);
void NumComparisons(ifstream &File, avlTree &Atree, BSTree &Btree);



int main()
{
    srand(2342);
	avlTree A;
    BSTree B;

	ifstream infile;

	//to visually see when the files are loaded into the trees
	cout << "loading adjectives" << "\n";
	//to load the files into the trees
	LoadTree("adjectives.txt", "adjectives", A, B);
	cout << "done" << "\n";
	cout << "loading adverbs" << "\n";
	LoadTree("adverbs.txt", "adverbs", A, B);
	cout << "done" << "\n";
	cout << "loading animals" << "\n";
	LoadTree("animals.txt", "animals", A, B);
	cout << "done" << "\n";
	cout << "loading nouns" << "\n";
	LoadTree("nouns.txt", "nouns", A, B);
	cout << "done" << "\n";
	cout << "loading verbs" << "\n";
	LoadTree("verbs.txt", "verbs", A, B);
	cout << "done" << "\n";

	infile.open("tenthousandwords.txt");
	//calls function to read in crazy words from file
	//then compare to what are in the trees
	NumComparisons(infile, A, B);
	infile.close();

    // Show a graphviz linked version of the tree. 
	A.graphVizOut("avlTree_viz.txt");
    B.GraphVizOut("bsTree_viz.txt");

	system("pause");
    return 0;
}

/**
* Function:	LoadTree
* Purpose:
*		Loads in the words from each file into the AVL tree
*		and into the BS tree
* Output:
*		none
*/
void LoadTree(string FileName, string type, avlTree &Atree, BSTree &Btree)
{
	ifstream fin;
	string word;

	// open the file for reading
	fin.open (FileName);

	// used as a counter
	int i = 0;

	// runs untill end of file or till 5000

	while(fin >> word)
	{
		//inserts words into AVL tree
		Atree.insert(word, type);
		//inserts words into BS tree
		Btree.insert(word, type);
		i++;
	}

	fin.close();
}

/**
* Function:	NumComparisons
* Purpose:
*		calls the methods in the classes to return that calculated results
*
* Output:
*		none
*/
void NumComparisons(ifstream &File, avlTree &Atree, BSTree &Btree)
{
	string word;
	int num = 0;
	ofstream output;

	//while file not empty
	while (File >> word)
	{	//calls search functions at also counts comparisons and word 
		//usages in the trees
		Atree.searchCount(word);
		Btree.searchCount(word);
	}
	output.open("analysis.out");
	//prints values in the file
	output << "Marissa Norris" << endl;
	output << "\n" << "BST Comparisons = " << Btree.getSum();
	output << "\n" << "AVL Comparisons = " << Atree.getSum();
	output << "\n" << "Number of Adjectives = " << Btree.getAdj();
	output << "\n" << "Number of Adverbs = " << Btree.getAdv();
	output << "\n" << "Number of Nouns = " << Btree.getNou();
	output << "\n" << "Number of Verbs = " << Btree.getVeb();

	output.close();
}