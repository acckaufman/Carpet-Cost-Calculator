#include <iostream>
#include <iomanip>
#include "FeetInches.h"
#include "RoomDimension.h"
#include "RoomCarpet.h"
using namespace std;

int main()
{
	RoomCarpet carpet;	//Create an instance of a RoomCarpet object
	char again = 'n';	//For use in do-while loop, to ask if user wants to repeat the program

	cout << "This program calculates the total cost of carpet." << endl << endl;

	do
	{
		int number;			//Temporary input variable (int)
		double number2;		//Temporary input variable (double)

		cout << "Please enter the length of the room in feet and inches." << endl;
		cout << "Feet: ";
		cin >> number;
		carpet.setLengthFeet(number);	//Use the RoomCarpet mutator functions to assign the feet and inches of the length and width, continued below
		cout << "Inches: ";
		cin >> number;
		carpet.setLengthInches(number);

		cout << "Now enter the width of the room in feet and inches." << endl;
		cout << "Feet: ";
		cin >> number;
		carpet.setWidthFeet(number);
		cout << "Inches: ";
		cin >> number;
		carpet.setWidthInches(number);

		cout << "What is the cost of the carpet per square foot? $";
		cin >> number2;
		carpet.setCost(number2);

		//Calculate and display the total cost of the carpet for the user, based on the information they entered.
		cout << "The total cost of this carpet will be $" << fixed << showpoint << setprecision(2) << carpet.calcCost() << "." << endl;

		cout << "Would you like to calculate the cost of another carpet? (y/n): ";
		cin >> again;
	} while (again == 'y' || again == 'Y');

	cout << endl << "Thank you for using this program." << endl << endl;
	system("pause");
	return 0;
}