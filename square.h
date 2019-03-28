/* The interface for the Square Class.
All functions are called by the puzzle class
through which they are implemented. 
*/

#pragma once

// declaration of the friend puzzle class
class Puzzle;

class Square
{
protected:
	
	// value variable for the square object
	int value;
	// bool flag for the square object
	bool fixedVal;
	// sets the square object value 
	bool setValue(int val);
	// reads the fixedVal variable and returns true if fixed false if not
	bool readfixed();

public:
	// defualt constructor
	Square();
	// defualt deconstructor
	~Square();
	
	//retrieves a const reference to the square value called by 
	// the puzzle class. returns an int value
	int getValue() const ; 

	// Friend class allows puzzle to access members of the 
	// the square class including protected values.
	friend class Puzzle;
	
};

