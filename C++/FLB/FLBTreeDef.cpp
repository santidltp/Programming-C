#include "FLBTree.h"



Node* Tree::Find(char* ID)
		{
			Node * pCurrent = pRoot;
			while (stricmp(pCurrent->ID ,ID) != 0)
			{
				if (strcmp(ID,pCurrent->ID ) > 0)
					pCurrent = pCurrent->pLeftLeaf;
				else 
					pCurrent = pCurrent->pRightLeaf;
				if(pCurrent==NULL)
					return NULL;
			}
			return pCurrent;
		}

void Tree:: insert(char* fName, char * lName, char* ID, int pass, char* cAcc, char* sAcc, double cBal, double sBal)
	{

		Node* pNewNode = new Node;
		strcpy(pNewNode->lName, lName);
		strcpy(pNewNode->fName, fName);
		strcpy(pNewNode->ID, ID);
		pNewNode->password=pass;
		strcpy(pNewNode->cAccount, cAcc);
		strcpy(pNewNode->sAccount, sAcc);
		pNewNode->cBalance = cBal;
		pNewNode->sBalance = sBal;

		if(pRoot == NULL)
				pRoot=pNewNode;
			else
			{
				Node* pCurrent = pRoot;
				Node* pParent;
				while(true)
					{
						pParent = pCurrent;
						if(stricmp(ID, pCurrent->ID)>=0)
						{
							pCurrent = pCurrent->pLeftLeaf;
							if(pCurrent == NULL)
								{
									pParent->pLeftLeaf = pNewNode;
									return;
								}
						}
						else
						{
							pCurrent = pCurrent->pRightLeaf;
							if(pCurrent == NULL)
							{
								pParent->pRightLeaf = pNewNode;
								return;	
							}	
						}
					}
			}
	}	

void Tree :: appTree(Node *nPerson)
{

	
	if(nPerson != NULL)
	{
	
	appTree(nPerson->pRightLeaf);
		save << nPerson->ID << setw(8) << nPerson->password << setw(12) << nPerson->fName << setw(15) << nPerson->lName 
			 << setw(12) << nPerson->cAccount << setw(12) << nPerson->cBalance << setw(12) << nPerson->sAccount << setw(8)
			 << nPerson->sBalance << endl;
	
	appTree(nPerson->pLeftLeaf);
		
	
	
	}
	


}

void Tree::openFile()
{
	save.open("UpDatedFile.txt");
	
}
void Tree::closeFile()
{
	save.close();

}
