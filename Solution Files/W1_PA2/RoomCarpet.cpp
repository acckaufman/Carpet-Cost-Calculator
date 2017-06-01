#include "RoomCarpet.h"
#include "RoomDimension.h"
#include "FeetInches.h"
using namespace std;

//Default Constructor
RoomCarpet::RoomCarpet()
{
}

//Calculate the total cost of the carpet
double RoomCarpet::calcCost()
{
	double finalCost;					//Variable to store the final cost of the carpet
	area = length.multiply(width);		//Calculate and store the area of the room based on the dimensions the user entered
	finalCost = (static_cast<double>(area.getFeet()) * unitCost) + ((static_cast<double>(area.getInches())) / 12 * unitCost);	//Calculate the cost of the carpet

	return finalCost;
}

//Mutator functions
void RoomCarpet::setLengthFeet(int f)
{
	length.setFeet(f);
}

void RoomCarpet::setLengthInches(int i)
{
	length.setInches(i);
}

void RoomCarpet::setWidthFeet(int f)
{
	width.setFeet(f);
}

void RoomCarpet::setWidthInches(int i)
{
	width.setInches(i);
}

void RoomCarpet::setCost(double c)
{
	unitCost = c;
}

//Destructor
RoomCarpet::~RoomCarpet()
{
}
