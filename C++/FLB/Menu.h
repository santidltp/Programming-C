/*	This is a Class created to to draw a box. With this Class
 *	you have the ability to change the size and the color of the box.
 *	It is called Menu and not Box, because the box is specially used 
 *	for Menus.
 *  -----------------------------------------------------
 *	Update: This class has been updated so when it comes to use it
 *			the code that is going to be used in the main it is going 
 *			to be more eficient that it used to be.	For example,
 *			the color changer function wasn't on the constructor and you
 *			needed to call the function in the main, now it is on the constructor
 *			so the function that sets the colors up doesn't have to be 
 *			called in main. 
 *			Another efficiency that has been added to this clas is the 
 *			printing function in the constructor, in this way you don't
 *			have to call it in the main everytime you want to print the box,
 *			the constructor does it for you.
 *			The color that used to be "AQUA" now is called with its original
 *			name "CYAN". 
 *			And finally the member function of the class called setBoxColor 
 *			now is called setBoxLetter, and accepts one parameter string. This
 *			Function didn't used to do anything and its been fixed so it change
 *			the color of the letter inside the box.
 *
 *
 *
 *
 *
 *
 *	Developed by: Santiago De La Torre
 *	Educational center: Bunker Hill Community College
 *  Created in: February 24, 2010. 
 *	Last Modification: April 27, 2010
 *
 */

	#include <iomanip>
	#include <windows.h>
	#include <iostream>
	#include <string>

	using namespace std;

	class Menu
	{
	private:
		string cBack;
		string cText;
		COORD position;
		int weight , lenght;
	
	public:
		// Default Cunstructor
		Menu()
		{
			cBack = '\0';
			cText = '\0';
			position.X = 0;
			position.Y = 0;
			weight = 5;
			lenght = 3;
			printBox();
		};
	
		// Constructors
		Menu(string back, string letter, int w, int l, int x, int y)
		{
			weight = w; 
			lenght = l;
			position.X = x;
			position.Y = y;
			setBackLetter(back,letter);
			printBox();
			
		};
		
		Menu(string foreground, string back, string letter, int w, int l, int x, int y)
		{
			weight = w; 
			lenght = l;
			position.X = x;
			position.Y = y;
			setBackLetter(back,letter);
			printBox();
			setBoxLetter(foreground);
		};
		
		//Accesor
		string getcBack()
		{return cBack;};
		string getcText()
		{return cText;};
		int getXPos()
		{return position.X;};
		int getYPos()
		{return position.Y;};
		int getweight()
		{return weight;};
		int getLenght()
		{return lenght;};
		
		//Mutators
		void setBackLetter(string back, string letter);
		void setPosition(int x, int y)
		{
			position.X = x;
			position.Y = y;
		};
		void setBoxSize(int w, int l)
		{
			weight = w;
			lenght = l;
		};
		void setBoxLetter(string);
		
		//Class Function to print a box.
		void printBox();
	};
