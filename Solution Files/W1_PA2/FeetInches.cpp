// Implementation file for the FeetInches class
#include <cstdlib>  // Needed for abs()
#include "FeetInches.h"

//BEGIN CLASS ASSIGNMENT FUNCTIONS PART 1

//Copy Constructor
FeetInches::FeetInches(const FeetInches &obj)
{
	feet = obj.feet;
	inches = obj.inches;
}

//************************************************************
// Definition of multiply function.  This function takes     *
// another feetInches object as a parameter, and multiplies  *
// its length by the length of the calling object, returning *
// the area of a room.										 *
//************************************************************

//Multiply function

FeetInches FeetInches::multiply(const FeetInches &obj)
{
	FeetInches temp;
	int length1, length2;		//Temporary holders for the lengths converted to inches
	double result;				//Store final result of feet and inches, expressed as a decimal

	length1 = (feet * 12) + inches;				//Length of calling object, expressed in inches
	length2 = (obj.feet * 12) + obj.inches;		//Length of second object, expressed in inches
	result = (static_cast<double>((length1 * length2))) / 144;			//Dimensions of room in square inches, which is then converted to feet and inches (a decimal number)

	temp.feet = static_cast<int>(result);					//Store only the integer portion of result in the temp object's feet attribute
	temp.inches = (result - static_cast<int>(result)) * 12;	//Subtract the integer portion of result to isolate the decimal portion of feet, then convert the decimal portion to inches

	return temp;				//Return the temp FeetInches object, which holds an area in square feet and square inches
}

//END CLASS ASSIGNMENT FUNCTIONS PART 1

//************************************************************
// Definition of member function simplify. This function     *
// checks for values in the inches member greater than       *
// twelve or less than zero. If such a value is found,       *
// the numbers in feet and inches are adjusted to conform    *
// to a standard feet & inches expression. For example,      *
// 3 feet 14 inches would be adjusted to 4 feet 2 inches and *
// 5 feet -2 inches would be adjusted to 4 feet 10 inches.   *
//************************************************************

void FeetInches::simplify()
{
   if (inches >= 12)
   {
      feet += (inches / 12);
      inches = inches % 12;
   }
   else if (inches < 0)
   {
      feet -= ((abs(inches) / 12) + 1);
      inches = 12 - (abs(inches) % 12);
   }
}

//**********************************************
// Overloaded binary + operator.               *
//**********************************************

FeetInches FeetInches::operator + (const FeetInches &right)
{
   FeetInches temp;

   temp.inches = inches + right.inches;
   temp.feet = feet + right.feet;
   temp.simplify();
   return temp;
}


//**********************************************
// Overloaded binary - operator.               *
//**********************************************

FeetInches FeetInches::operator - (const FeetInches &right)
{
   FeetInches temp;

   temp.inches = inches - right.inches;
   temp.feet = feet - right.feet;
   temp.simplify();  
   return temp;
}

//*************************************************************
// Overloaded prefix ++ operator. Causes the inches member to *
// be incremented. Returns the incremented object.            *
//*************************************************************

FeetInches FeetInches::operator ++ ()
{
   ++inches;
   simplify();
   return *this;
}

//***************************************************************
// Overloaded postfix ++ operator. Causes the inches member to  *
// be incremented. Returns the value of the object before the   *
// increment.                                                   *
//***************************************************************

FeetInches FeetInches::operator ++ (int)
{
   FeetInches temp(feet, inches);

   inches++;
   simplify();
   return temp;
}

//************************************************************
// Overloaded > operator. Returns true if the current object *
// is set to a value greater than that of right.             *
//************************************************************

bool FeetInches::operator > (const FeetInches &right)
{
   bool status;

   if (feet > right.feet)
      status = true;
   else if (feet == right.feet && inches > right.inches)
      status = true;
   else
      status = false;

   return status;
}

//************************************************************
// Overloaded < operator. Returns true if the current object *
// is set to a value less than that of right.                *
//************************************************************

bool FeetInches::operator < (const FeetInches &right)
{
   bool status;

   if (feet < right.feet)
      status = true;
   else if (feet == right.feet && inches < right.inches)
      status = true;
   else
      status = false;

   return status;
}

//*************************************************************
// Overloaded == operator. Returns true if the current object *
// is set to a value equal to that of right.                  *
//*************************************************************

bool FeetInches::operator == (const FeetInches &right)
{
   bool status;

   if (feet == right.feet && inches == right.inches)
      status = true;
   else
      status = false;

   return status;
}

//BEGIN CLASS ASSIGNMENT FUNCTIONS PART 2

//*************************************************************
// Overloaded = operator.                                     *
//*************************************************************

void FeetInches::operator = (const FeetInches &right)
{
	feet = right.feet;
	inches = right.inches;
}

//*************************************************************
// Overloaded >= operator. Returns true if the current object *
// is set to a value greater than or equal to that of right.  *
//*************************************************************

bool FeetInches::operator >= (const FeetInches &right)
{
	bool status;

	if (feet > right.feet)
		status = true;
	else if (feet == right.feet && inches >= right.inches)
		status = true;
	else
		status = false;

	return status;
}

//*************************************************************
// Overloaded <= operator. Returns true if the current object *
// is set to a value less than or equal to that of right.     *
//*************************************************************

bool FeetInches::operator <= (const FeetInches &right)
{
	bool status;

	if (feet < right.feet)
		status = true;
	else if (feet == right.feet && inches <= right.inches)
		status = true;
	else
		status = false;

	return status;
}

//*************************************************************
// Overloaded != operator. Returns true if the current object *
// is set to a value not equal to that of right.              *
//*************************************************************

bool FeetInches::operator != (const FeetInches&right)
{
	bool status;

	if (feet == right.feet && inches == right.inches)
		status = false;
	else
		status = true;

	return status;
}

//END CLASS ASSIGNMENT FUNCTIONS PART 2

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator<<(ostream &strm, const FeetInches &obj)
{
   strm << obj.feet << " feet, " << obj.inches << " inches";
   return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into FeetInches objects.    *
//********************************************************

istream &operator >> (istream &strm, FeetInches &obj)
{
   // Prompt the user for the feet.
   cout << "Feet: ";
   strm >> obj.feet;

   // Prompt the user for the inches.
   cout << "Inches: ";
   strm >> obj.inches;

   // Normalize the values.
   obj.simplify();

   return strm;
}

//*************************************************************
// Conversion function to convert a FeetInches object         *
// to a double.                                               *
//*************************************************************

FeetInches::operator double()
{
   double temp = feet;

   temp += (inches / 12.0);
   return temp;
}

//*************************************************************
// Conversion function to convert a FeetInches object         *
// to an int.                                                 *
//*************************************************************

FeetInches:: operator int()
{ 
   return feet; 
}




