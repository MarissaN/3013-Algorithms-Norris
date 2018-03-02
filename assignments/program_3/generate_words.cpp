///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            Assignment 3 - Crazy words
// Files:            generated_words.cpp
//					 analyze_trees.cpp
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
#include<fstream>
#include<string>

using namespace std;


//vectors
vector<string> Adj;
vector<string> Adv;
vector<string> Ani;
vector<string> Nou;
vector<string> Veb;

//prototypes
void WordCreator();
void ThreeWorded(vector<string> &Adj, vector<string> &Adv, vector<string> &Ani,
	vector<string> &Nou, vector<string> &Veb, ofstream &wordslist);
void FourWorded(vector<string> &Adj, vector<string> &Adv, vector<string> &Ani,
	vector<string> &Nou, vector<string> &Veb, ofstream &wordslist);
void FiveWorded(vector<string> &Adj, vector<string> &Adv, vector<string> &Ani,
	vector<string> &Nou, vector<string> &Veb, ofstream &wordslist);
string WordSelector(vector <string> &word);

int main()
{
	//calls function to create crazy word
	WordCreator();
}

/**
* Function:	WordCreator
* Purpose:
*		Creats the crazy words from a series of random numbers
*		functions, loops and choices
* Output:
*		none
*/
void WordCreator()
{
	ifstream infile;
	ofstream outfile;
	string word;
	int numWords;
	int i = 0;




	//the following are while loops created to place
	//the words with in each file in to their respective vectors
	infile.open("adjectives.txt");
	while (infile >> word)
	{
		Adj.push_back(word);
	}
	infile.close();

	infile.open("adverbs.txt");
	while (infile >> word)
	{
		Adv.push_back(word);
	}
	infile.close();

	infile.open("animals.txt");
	while (infile >> word)
	{
		Ani.push_back(word);
	}
	infile.close();

	infile.open("nouns.txt");
	while (infile >> word)
	{
		Nou.push_back(word);
	}
	infile.close();

	infile.open("verbs.txt");
	while (infile >> word)
	{
		Veb.push_back(word);
	}
	infile.close();

	//opens file to write in the crazy words to the file
	outfile.open("tenthousandwords.txt");

	//generates 10000 words
	while (i <= 10000) {
		numWords = 1 + rand() % 3;

		//switch/ case statement creats at random 3 - 5 worded crazy words
		switch (numWords) {
		case 1:
		{
			ThreeWorded(Adj, Adv, Ani, Nou, Veb, outfile);
			break;
		}
		case 2:
		{
			FourWorded(Adj, Adv, Ani, Nou, Veb, outfile);
			break;
		}
		default:
		{
			FiveWorded(Adj, Adv, Ani, Nou, Veb, outfile);
			break;
		}
		}
		i++;
	}
	outfile.close();
	return;
}

/**
* Function:	ThreeWorded
* Purpose:
*		creates three worded crazy word component through a series of options
*		in a switch and case statement 
* Output:
*		none
*/
void ThreeWorded(vector<string> &Adj, vector<string> &Adv, vector<string> &Ani,
	vector<string> &Nou, vector<string> &Veb, ofstream &wordslist)
{


	int choice;
	string crazyWord;

	choice = 1 + rand() % 10;

	//provides 10 options for organization of components in the word
	switch (choice)
	{
	case 1: {
		//concatenate the crazy word
		crazyWord = WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	case 2: {
		crazyWord = WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	case 3: {
		crazyWord = WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		break;
	}
	case 4: {
		crazyWord = WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		break;
	}
	case 5: {
		crazyWord = WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		break;
	}
	case 6: {
		crazyWord = WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		break;
	}
	case 7: {
		crazyWord = WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	case 8: {
		crazyWord = WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		break;
	}
	case 9: {
		crazyWord = WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	default: {
		crazyWord = WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	}

	//prints the word in file
	wordslist << crazyWord << endl;


}

/**
* Function:	FourWorded
* Purpose:
*		creates four worded crazy word component through a series of options
*		in a switch and case statement
* Output:
*		none
*/
void FourWorded(vector<string> &Adj, vector<string> &Adv, vector<string> &Ani,
	vector<string> &Nou, vector<string> &Veb, ofstream &wordslist)
{

	int choice;
	string crazyWord;

	choice = 1 + rand() % 10;

	switch (choice)
	{
	case 1: {
		crazyWord = WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	case 2: {
		crazyWord = WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		break;
	}
	case 3: {
		crazyWord = WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		break;
	}
	case 4: {
		crazyWord = WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		break;
	}
	case 5: {
		crazyWord = WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	case 6: {
		crazyWord = WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		break;
	}
	case 7: {
		crazyWord = WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		break;
	}
	case 8: {
		crazyWord = WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		break;
	}
	case 9: {
		crazyWord = WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		break;
	}
	default: {
		crazyWord = WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	}


	wordslist << crazyWord << endl;

}

/**
* Function:	FiveWorded
* Purpose:
*		creates five worded crazy word component through a series of options
*		in a switch and case statement
* Output:
*		none
*/
void FiveWorded(vector<string> &Adj, vector<string> &Adv, vector<string> &Ani,
	vector<string> &Nou, vector<string> &Veb, ofstream &wordslist)
{

	int choice;
	string crazyWord;

	choice = 1 + rand() % 10;

	switch (choice)
	{
	case 1: {
		crazyWord = WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	case 2: {
		crazyWord = WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		break;
	}
	case 3: {
		crazyWord = WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		break;
	}
	case 4: {
		crazyWord = WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	case 5: {
		crazyWord = WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	case 6: {
		crazyWord = WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		break;
	}
	case 7: {
		crazyWord = WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		break;
	}
	case 8: {
		crazyWord = WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		break;
	}
	case 9: {
		crazyWord = WordSelector(Nou);
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Adj);
		crazyWord += " ";
		crazyWord += WordSelector(Ani);
		break;
	}
	default: {
		crazyWord = WordSelector(Ani);
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Veb);
		crazyWord += "ing";
		crazyWord += " ";
		crazyWord += WordSelector(Adv);
		crazyWord += " ";
		crazyWord += WordSelector(Nou);
		break;
	}
	}


	wordslist << crazyWord << endl;
}

/**
* Function:	WordSelector
* Purpose:
*		randomly selects a word from the array
*
* Output:
*		returns the word selected
*/
string WordSelector(vector <string> &word)
{
	int num;
	int location;

	//gets the size of the vector 
	num = word.size();

	//randomly creates the index of the vector location
	location = rand() % num;

	return word[location];
}
