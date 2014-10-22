#ifndef NODE_H
#define NODE_H 

#include <iostream>
#include <stack>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
class Node 
{
public:
	
	char fName[10];
	char lName[20];
	char ID[20];
	int password;
	char cAccount[20];
	char sAccount[20];
	double cBalance;
	double sBalance;
	Node * pLeftLeaf;
	Node * pRightLeaf;
	Node():  pLeftLeaf(NULL), pRightLeaf(NULL){}
};

class Tree
{
	private:
		Node * pRoot;
		ofstream save;

	public:

		//Constructor
	Tree(): pRoot(NULL)
		{}
	//Member Funtions
	Node* Find(char* ID);
	void openFile();
	void closeFile();
	void destroyRec(Node *actualRecord);
	void saveTree()
	{appTree(pRoot);}
	void appTree(Node *);
	void insert(char* fName, char * lName, char* ID, int pass, char* cAcc, char* sAcc, double cBal, double sBal);
};

#endif