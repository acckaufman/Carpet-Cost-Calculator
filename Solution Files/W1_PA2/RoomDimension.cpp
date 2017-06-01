#include "RoomDimension.h"
#include "FeetInches.h"
using namespace std;

//Default constructor
RoomDimension::RoomDimension()
{
	length.setFeet(0);
	length.setInches(0);
	width.setFeet(0);
	width.setInches(0);
}

//Mutator Functions
FeetInches RoomDimension::calcArea(FeetInches &length, FeetInches &width)
{
	FeetInches temp;				//Temporary storage variable
	temp = length.multiply(width);	//Use the FeetInches multiply function to get the dimensions of the room, and store in temp
	return temp;					//Return the FeetInches object containing the results of the multiplication
}

//Accessor Functions
FeetInches RoomDimension::getLength() const
{
	FeetInches temp;
	temp.setFeet(length.getFeet());
	temp.setInches(length.getInches());
	return temp;
}

FeetInches RoomDimension::getWidth() const
{
	FeetInches temp;
	temp.setFeet(width.getFeet());
	temp.setInches(width.getInches());
	return temp;
}

RoomDimension::~RoomDimension()
{
}
