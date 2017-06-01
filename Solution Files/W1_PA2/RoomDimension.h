#pragma once
#include "FeetInches.h"

class RoomDimension
{
private:
	FeetInches length;
	FeetInches width;
public:
	//Default constructor
	RoomDimension();

	//Mutator Functions
	FeetInches calcArea(FeetInches &, FeetInches &);

	//Accessor Functions
	FeetInches getLength() const;
	FeetInches getWidth() const;

	//Destructor
	~RoomDimension();
};

