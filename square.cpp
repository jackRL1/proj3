/* This class is used for creating Square objects and
assigning them to the square array in the puzzle class.


*/

#include "square.h"


// Sets the value for a square object
bool Square::setValue(int num)
{
	value = num;

	return true;
}

//reads the value of the fixedVal bool flag.  
bool Square::readfixed()
{
	return fixedVal;
}

// this is the constructor for the Square object and 
// initializes its value to 0
Square::Square()
{
	value = 0;
}

// defualt deconstructor
Square::~Square()
{

}

// retieves the value at a location
// in side the square array but does not access it directly
int Square::getValue() const
{
	return value;
}
