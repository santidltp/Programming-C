
#include"Menu.h"

void Menu::setBackLetter(string name, string letter)
{

	cBack = name;
	cText = letter;

	if (name == "BLACK")
	{
		if(letter == "GRAY") system("color 08");
		else if (letter == "BLUE") system("color 09");
		else if (letter == "GREEN") system("color 0A");
		else if (letter == "CYAN") system("color 0B"); 
		else if (letter == "RED") system("color 0C"); 
		else if (letter == "PURPLE") system("color 0D"); 
		else if (letter == "YELLOW") system("color 0E");
		else if (letter == "WHITE") system("color 0F");
	}

	if (name == "BLUE")
	{
		if(letter == "GRAY") system("color 18");
		else if (letter == "BLUE") system("color 19");
		else if (letter == "GREEN") system("color 1A");
		else if (letter == "CYAN") system("color 1B"); 
		else if (letter == "RED") system("color 1C"); 
		else if (letter == "PURPLE") system("color 1D"); 
		else if (letter == "YELLOW") system("color 1E");
		else if (letter == "WHITE") system("color 1F");
	}

	if (name == "GREEN")
	{
		if(letter == "GRAY") system("color 28");
		else if (letter == "BLUE") system("color 29");
		else if (letter == "GREEN") system("color 2A");
		else if (letter == "CYAN") system("color 2B"); 
		else if (letter == "RED") system("color 2C"); 
		else if (letter == "PURPLE") system("color 2D"); 
		else if (letter == "YELLOW") system("color 2E");
		else if (letter == "WHITE") system("color 2F");
	}

	if (name == "CYAN")
	{
		if(letter == "GRAY") system("color 38");
		else if (letter == "BLUE") system("color 39");
		else if (letter == "GREEN") system("color 3A");
		else if (letter == "CYAN") system("color 3B"); 
		else if (letter == "RED") system("color 3C"); 
		else if (letter == "PURPLE") system("color 3D"); 
		else if (letter == "YELLOW") system("color 3E");
		else if (letter == "WHITE") system("color 3F");
	}


	if (name == "RED")
	{
		if(letter == "GRAY") system("color 48");
		else if (letter == "BLUE") system("color 49");
		else if (letter == "GREEN") system("color 4A");
		else if (letter == "CYAN") system("color 4B"); 
		else if (letter == "RED") system("color 4C"); 
		else if (letter == "PURPLE") system("color 4D"); 
		else if (letter == "YELLOW") system("color 4E");
		else if (letter == "WHITE") system("color 4F");
	}

	if (name == "PURPLE")
	{
		if(letter == "GRAY") system("color 58");
		else if (letter == "BLUE") system("color 59");
		else if (letter == "GREEN") system("color 5A");
		else if (letter == "CYAN") system("color 5B"); 
		else if (letter == "RED") system("color 5C"); 
		else if (letter == "PURPLE") system("color 5D"); 
		else if (letter == "YELLOW") system("color 5E");
		else if (letter == "WHITE") system("color 5F");
	}

	if (name == "YELLOW")
	{
		if(letter == "GRAY") system("color 68");
		else if (letter == "BLUE") system("color 69");
		else if (letter == "GREEN") system("color 6A");
		else if (letter == "CYAN") system("color 6B"); 
		else if (letter == "RED") system("color 6C"); 
		else if (letter == "PURPLE") system("color 6D"); 
		else if (letter == "YELLOW") system("color 6E");
		else if (letter == "WHITE") system("color 6F");
	}


	if (name == "WHITE")
	{
		if(letter == "GRAY") system("color 78");
		else if (letter == "BLUE") system("color 79");
		else if (letter == "GREEN") system("color 7A");
		else if (letter == "CYAN") system("color 7B"); 
		else if (letter == "RED") system("color 7C"); 
		else if (letter == "PURPLE") system("color 7D"); 
		else if (letter == "YELLOW") system("color 7E");
		else if (letter == "WHITE") system("color 7F");
	}
}

void Menu::printBox()
{

	setBoxLetter(cText);

	COORD cord1, cord2;

	int upLeftCorner = 201,
	upRightCorner = 187,
	downLeftCorner = 200,
	downRightCorner= 188, 
	hori = 205,
	verti = 186;

	int x = 21;
	int y = 1;
	cord1.X = position.X;
	cord1.Y = position.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord1);
	cout << char(upLeftCorner);

	cord2.X = position.X + weight;
	cord2.Y = position.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord2);
	cout << char(upRightCorner);

	for (int z=1; z<lenght; z++)

	{
		cord1.X = position.X;
		cord1.Y++ ;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord1);
		cout << char(verti) << setw(weight) << char(verti);

	}
	for(int i = 1;  i<weight; i++)
	{
		cord1.X = position.X +i;
		cord1.Y = position.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord1);
		cout << char(hori);
	
		cord2.X = position.X +i;
		cord2.Y = position.Y + lenght;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord2);
		cout << char(hori);
	
	}



	cord1.X = position.X ;
	cord1.Y = position.Y + lenght;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord1);
	cout << char(downLeftCorner);

	cord2.X = position.X + weight;
	cord2.Y = position.Y + lenght;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord2);
	cout << char(downRightCorner);
}





void Menu::setBoxLetter(string backcolor)
{
	if (backcolor == "BLACK")
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0x0000);
	else if (backcolor == "BLUE")
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0x0001);
	else if (backcolor == "GREEN")
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0x0002);
	else if (backcolor == "CYAN")
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0x0003);
	else if (backcolor == "RED")
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0x0004);
	else if (backcolor == "PURPLE")
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0x0005);
	else if (backcolor == "YELLOW")
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0x0006);
	else if (backcolor == "WHITE")
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0x0007);
}

















