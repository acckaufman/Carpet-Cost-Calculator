#pragma once
#include "FeetInches.h"

class RoomCarpet
{
private:
	FeetInches length;		//Length of the room
	FeetInches width;		//Width of the room
	FeetInches area;		//Area of the room in square feet and square inches
	double unitCost;		//Cost of the carpet per square foot
public:
	//Constructor
	RoomCarpet();

	double calcCost();

	//Mutator functions
	void setLengthFeet(int);
	void setLengthInches(int);
	void setWidthFeet(int);
	void setWidthInches(int);
	void setCost(double);

	//Accessor functions

	//Destructor
	~RoomCarpet();
};

