/**This Program is a simulation of bank program, where the user inputs his/her ID
 * and password and then can perform allowed mathematical operations with his/her bank account.
 * In this program is included a Binary Tree, where all the records are going to be loaded.
 * The printing functions are recursive calling eachother, so it is like creating a loop
 * with functions, for instance, printWelcome() calls printMenu() and this one will call
 * one the functions that belongs to the menu and each one of those functions calls back printWelcome().
 * After 10 people are logged to perform operations on their bank accounts, the program saves 
 * all the records into the file "UpDatedFile.txt" sorted by ID.
 *
 * Developed by Santiago De La Torre
 * Educational Center: Bunker Hill Community College
 * Last Modification: 17 May 2010
 */




#include <iostream>
#include "FLBTree.h"
#include <fstream>
#include <iomanip>
#include "Person.h"
//#include <conio.h>
#include "Menu.h"
//#include <Windows.h>

using namespace std;


	int getAcNum();
	void printWelcome();
	void exit();
	void transferFounds();
	void makeDeposit();
	void goodBye();
	void printWarning();
	void checkBalance();
	void withDrawal();
	void printMenu();
		int counter=0, iPeople=-1;
	Tree FBLTree;
	Node* found;
	

int main(){


	



	Person acOwner[10]  = {"A1234567",	1368,	"Santiago",		"DeLaTorre",	"12345678",	3000,	"87654321",	500,
							"B1234567",	5378,	"Elijah",		"Collins",		"23456789",	4000,	"98765432",	1000,
							"D7654321",	7879,	"Collin",		"Fuda",		"11110000",	2400,	"57575321",	180,
							"Z7654321",	1234,	"Bill"	,		"Armstrong",	"33355441",	10000,	"23555182",	20000,
							"C1234567",	7741,	"Brondom",		"LeBlanc",		"56724193",	6310,	"80239275",	200,
							"D1234567",	5017,	"Said",			"Masawi",		"78945621",	2569,	"98705421",	200,
							"E1234567",	9186,	"Nesto",		"Monell",		"21516894",	3535,	"18241991",	100,
							"A2345432",	1111,	"Ekin"	,		"Uygur",		"87443211",	3000,	"33321992",	450,
							"F1234567",	9291,	"Justine",		"Venti",		"00145831",	5986,	"00321456",	0,
							"G1234567",	1456,	"Jason"	,		"Derulo",	   "99965412",		2500,	"77321341",	0};

	
	


	ofstream save("startValues.txt");
	for (int x=0; x<10; x++)
		save << acOwner[x].ID << setw(8) << acOwner[x].password << setw(12) << acOwner[x].fName << setw(15) << acOwner[x].lName 
			 << setw(12) << acOwner[x].cAccount << setw(12) << acOwner[x].cBalance << setw(12) << acOwner[x].sAccount << setw(8)
			 << acOwner[x].sBalance << endl;
	save.close();
	

	Person *thisPerson = new Person[10];
	ifstream read("startValues.txt");

		int count=0;
	while (!read.eof())
	{
		
		  read  >> thisPerson[count].ID   ;
		  read  >> thisPerson[count].password ;
		  read  >> thisPerson[count].fName ;
		  read  >> thisPerson[count].lName ;
		  read	>> thisPerson[count].cAccount;
		  read	>> thisPerson[count].cBalance ;
		  read	>> thisPerson[count].sAccount;
		  read	>> thisPerson[count].sBalance ;
	count++;
	if (count == 10)
		break;
	}
	read.close();		



	for (int i=0; i<10; i++)
		::FBLTree.insert(thisPerson[i].fName,thisPerson[i].lName, thisPerson[i].ID, thisPerson[i].password,
		thisPerson[i].cAccount,thisPerson[i].sAccount,thisPerson[i].cBalance,thisPerson[i].sBalance );




	system("cls");
	printWelcome();


	

	return 0;
}


void  printWelcome(){
	Menu welcome("BLACK","BLUE","RED", 50,17,15,2);
		char ID[20];
		char passtemp[10];
		char idtemp[10];
		char subtemp;
		int password=0;
		
	
	COORD position;
	position.X=27;
	position.Y=5;


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Welcome To First Last Bank!";
	
	position.X+=3; position.Y+=4;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Enter ID: ";



	
 position.Y+=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Enter Password: ";

	position.X+=10;	 position.Y-=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	

	
	
		for(int i=0; i<8; i++)
	{
	subtemp=getch();	

	if(i==0 && toupper(subtemp) >=65 && toupper(subtemp) <=90)
	{
		cout << (char)toupper(subtemp);
		idtemp[i]= (char)toupper(subtemp);
	}
	else if(i>=1 && subtemp>=48 && subtemp<=57)
	{
		idtemp[i] = subtemp;
		cout << subtemp;
	}
	else 
		i--;

	}
	idtemp[i]='\0';

	strcpy(ID,idtemp);
	



	::found = FBLTree.Find(ID);
	position.X+=6; position.Y+=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	
	

	

	

	for( i=0; i<4; i++)
	{
	subtemp=getch();	
	if(subtemp>=48 && subtemp<=57)
	{
		passtemp[i] = subtemp;
		cout << "*";
	}
	else 
		i--;

	}
	
	password=atoi(passtemp);


	

	if(::found!=NULL && stricmp(::found->ID,ID)==0 && ::found->password==password)
	   {
		::counter=0;
		printMenu();		
		}
	else
	{
		
		::counter++;
		if(::counter == 3)
		{
			system("cls");
			printWarning();
		}
	position.X-=33;	position.Y+=10;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Either the user or passwrod is incorrect, please try it again! " ;
	
	printWelcome();
	

	}


}

void printWarning()
{
	Menu Warning("BLACK","RED","RED", 50,17,15,2);

	COORD position;
	position.X=37;
	position.Y=5;


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Warning!";

	position.X-=13;		position.Y+=4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "The system its been shout down";

		position.Y+=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "for security porpuses";

			position.Y+=2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "wait for the system to be released";

			position.Y+=10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);



	Sleep(300000);
	printWelcome();

}

void printMenu()
{
	system("cls");
	Menu welcome("BLACK","BLUE","RED", 50,17,15,2);

	







	::iPeople++; // to save records



	if(::iPeople==10)
{
		::FBLTree.openFile();
		::FBLTree.saveTree();
		::FBLTree.closeFile();
		::iPeople=-1;
}
		
		
		
		
		COORD position;
	position.X=27;
	position.Y=5;


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Select an action to perform";

position.X+=3;	position.Y+=3;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
cout << "1. Make a Deposit";

position.Y++;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
cout << "2. Make a Withdrawal";

position.Y++;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
cout << "3. Check Balance";

position.Y++;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
cout << "4. Transfer Founds";

position.Y++;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
cout << "5. Exit";

			position.Y+=10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);

	switch(getch())
	{
	case '1': makeDeposit(); break;
	case '2': withDrawal(); break;
	case '3': checkBalance(); break;
	case '4': transferFounds();break;
	case '5': exit();  break;
	
	
	
	
	
	}


}

void checkBalance()
{

	Menu welcome("BLACK","BLUE","RED", 50,17,15,2);

	int iAcNum=0, iChNum=0, iSavNum;


	COORD position;
	position.X=17;
	position.Y=3;

	iChNum=atoi(::found->cAccount);
	iSavNum=atoi(::found->sAccount);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Please introduce the Account";

	position.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "number you want to check: ";
	


	
	iAcNum= getAcNum();
	if(iChNum==iAcNum){

	 position.Y+=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Name: " << ::found->fName;

			 position.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Last name:: " << ::found->lName;

	 position.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Checking Account: " << ::found->cAccount;

	 position.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Checking Balance: $" << ::found->cBalance;
	goodBye();
	
	}
		
	else if(iSavNum== iAcNum)
	{
	
	
		 position.Y+=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Name: " << ::found->fName;

		 position.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Last Name: " << ::found->lName;

	position.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Savings Account: " << ::found->sAccount;



	 position.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Savings Balance: $" << ::found->sBalance;

	goodBye();	
	
	
	}
	
	
	else
	{
		position.Y+=17;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
		cout << "Incorrect Number, please try it again";
		checkBalance();

	}		

	
	system("cls"); 
	printWelcome();

	



}

int getAcNum()
{
	char temp[10], subtemp;
	int return1=0;

	for (int i =0; i<8; i++)
	{
		subtemp=getch();
		if(subtemp>=48 && subtemp<=57)
		{
			temp[i] = subtemp;
			cout << subtemp;
		}

		else
			i--;
		
	
	}
	return1=atoi(temp);
return return1;
}

void  goodBye()
{
char finish;

	COORD position;
	position.X=20;
	position.Y=18;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Please hit Enter when you are done!";
	
	finish=getch();
	while(finish != 13)
		finish=getch();
	

}

void withDrawal()
{
	
	Menu withDraw("BLACK","BLUE","RED", 50,17,15,2);


	char finish, temp[20];
	int iAcNum=0, iChNum=0, iSavNum=0, iMoney=0;


	COORD position;
	position.X=17;
	position.Y=3;

	iChNum=atoi(::found->cAccount);
	iSavNum=atoi(::found->sAccount);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Please introduce the Account";

	position.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "number you want to take money from: ";
	

		position.Y+=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Enter the amount";

		position.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "of money to withdraw: ";

	position.X+=36;	position.Y-=3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);

	iAcNum= getAcNum();

	
	position.X-=14;	position.Y+=3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	gets(temp);
	iMoney=atoi(temp);



	
	if(iChNum==iAcNum)
	{
		if(iMoney<=::found->cBalance && iMoney>=0)
		{
			::found->cBalance-=iMoney;
			
			position.X=25;
			position.Y=9;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Withdrawal Permitted";

			position.Y+=2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Name: " << ::found->fName;
			
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Current Balance: " << ::found->cBalance;
			goodBye();
		}
		else
		{
			position.X-=12;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Sorry, not enough founds";
			
			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				withDrawal();
			if(toupper(finish) == 'F')
				printWelcome();

		}
	}

	else if (iSavNum==iAcNum)
	{
		if(iMoney<=::found->sBalance && iMoney>=0)
		{
			::found->sBalance-=iMoney;
			position.X=25;
			position.Y=9;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Withdrawal Permitted";

			position.Y+=2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Name: " << ::found->fName;
			
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Current Balance: " << ::found->sBalance;
			goodBye();
		}
		else
		{
			position.X-=12;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Sorry, not enough founds";
		

			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				withDrawal();
			if(toupper(finish) == 'F')
				printWelcome();
	}
	}		
	else
	{
			position.X-=17;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Sorry, not a valid account number";
			
			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				withDrawal();
			if(toupper(finish) == 'F')
				printWelcome();
	
	
	}

	
	
	
	
printWelcome();

}


void makeDeposit()
{
Menu withDrawal("BLACK","BLUE","RED", 50,17,15,2);


	char finish, temp[20];
	int iAcNum=0, iChNum=0, iSavNum=0, iMoney=0;


	COORD position;
	position.X=17;
	position.Y=3;

	iChNum=atoi(::found->cAccount);
	iSavNum=atoi(::found->sAccount);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Please introduce the Account";

	position.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "number you want to deposit: ";
	

		position.Y+=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Enter the amount";

		position.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "of money to deposit: ";

	position.X+=28;	position.Y-=3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);

	iAcNum= getAcNum();

	
	position.X-=7;	position.Y+=3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	gets(temp);
	iMoney=atoi(temp);



	
	if(iChNum==iAcNum)
	{
		if( iMoney>=0)
		{
			::found->cBalance+=iMoney;
			
			position.X=25;
			position.Y=9;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Deposit Permitted";

			position.Y+=2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Name: " << ::found->fName;
			
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Current Balance: " << ::found->cBalance;
			goodBye();
		}
		else
		{
			position.X-=12;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Sorry, not negative numbers";
			
			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				makeDeposit();
			if(toupper(finish) == 'F')
				printWelcome();

		}
	}

	else if (iSavNum==iAcNum)
	{
		if( iMoney>=0)
		{
			::found->sBalance+=iMoney;
			position.X=25;
			position.Y=9;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Deposit Permitted";

			position.Y+=2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Name: " << ::found->fName;
			
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Current Balance: " << ::found->sBalance;
			goodBye();
		}
		else
		{
			position.X-=12;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Sorry, not negative numbers";
		

			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				makeDeposit();
			if(toupper(finish) == 'F')
				printWelcome();
	}
	}		
	else
	{
			position.X-=17;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Sorry, not a valid account number";
			
			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				makeDeposit();
			if(toupper(finish) == 'F')
				printWelcome();
	
	
	}

	
	
	
	
printWelcome();

}

void transferFounds()
{




Menu withDrawal("BLACK","BLUE","RED", 50,17,15,2);


	char finish, temp[20];
	int iAcNum=0, iChNum=0, iSavNum=0, iMoney=0, iTarget=0;


	COORD position;
	position.X=17;
	position.Y=3;

	iChNum=atoi(::found->cAccount);
	iSavNum=atoi(::found->sAccount);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Please introduce the source Account: ";


		position.Y+=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Enter the target acount: ";


			position.Y+=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Amount of money to transfer: ";

	position.X+=37;	position.Y-=4;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);

	iAcNum= getAcNum();

	
	position.X-=12;	position.Y+=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	iTarget=getAcNum();
	
	
	position.X+=4;	position.Y+=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	
	
	gets(temp);
	iMoney=atoi(temp);

	if(iAcNum == iTarget)
	{
			position.X-=25;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Sorry, the account numbers are the same";
			
			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				transferFounds();
			if(toupper(finish) == 'F')
				printWelcome();
	
	}
	if(iMoney<0)
	{
				position.X-=25;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Negative numbers are invalid";
			
			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				transferFounds();
			if(toupper(finish) == 'F')
				printWelcome();
	}

	if(!(iChNum==iAcNum || iSavNum == iAcNum))
	{
			position.X-=25;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Invalid Source Account";
			
			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				transferFounds();
			if(toupper(finish) == 'F')
				printWelcome();
	
	}

		if(!(iChNum==iTarget || iSavNum==iTarget))
	{
			position.X-=25;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Invalid Target Account";
			
			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				transferFounds();
			if(toupper(finish) == 'F')
				printWelcome();
	
	}
	
	
	if(iChNum==iAcNum && iSavNum==iTarget)
	{
	
		if(iMoney>::found->cBalance)
	{
				position.X-=25;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Unavailable Founds To Transfer";
			
			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				transferFounds();
			if(toupper(finish) == 'F')
				printWelcome();
	}
		
		::found->cBalance-=iMoney;
		::found->sBalance+=iMoney;
			
			position.X=25;
			position.Y=9;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Transfer Completed Successfully";

			position.Y+=2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Name: " << ::found->fName;
			
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Last Name: " << ::found->lName;
			
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Current Savings Balance: " << ::found->sBalance;

				position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Current Checking Balance: " << ::found->cBalance;
			goodBye();
	}

	
	
	
	else if(iChNum==iTarget && iSavNum==iAcNum)
	{
			
		
		if(iMoney>::found->sBalance)
		{
			{
				position.X-=25;	position.Y+=3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Unavailable Founds To Transfer";
			
			position.X=25;
			position.Y=16;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[F] Finish";
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "[R] Retry";
			
			finish=getch();
			while(!(toupper(finish) == 82 || toupper(finish) == 70 ))
				finish=getch();

			cout << finish;
			if(toupper(finish) == 'R')
				transferFounds();
			if(toupper(finish) == 'F')
				printWelcome();
	}
		
		
		}
		
			::found->sBalance-=iMoney;
			::found->cBalance+=iMoney;
			
			position.X=25;
			position.Y=9;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Transfer Completed Successfully";

			position.Y+=2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Name: " << ::found->fName;
			
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Last Name: " << ::found->lName;
			
			position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Current Checking Balance: " << ::found->cBalance;

				position.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
			cout << "Current Savings Balance: " << ::found->sBalance;
			goodBye();
	}
	

	

	
	
printWelcome();

}






void exit()
{
Menu exit("BLACK","BLUE","RED", 50,17,15,2);
	COORD position;
	position.X=30;
	position.Y=5;


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Thanks for using!";

	position.X++; position.Y+=4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "First Last Bank";

	position.X--;	position.Y+=4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	cout << "Have a Nice Day!";

	Sleep(5000);
	printWelcome();


}




