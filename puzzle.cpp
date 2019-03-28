/* The puzzle class does all the heavy lifting for making the program able to 
solve puzzles. It accesses the Square class in order to make square objects and 
it recieves the input and assigns it to the Square array. The Puzzle class 
also holds the solve function for solving the Sudoku Puzzle.

*/

#include "puzzle.h"
#include "square.h"
#include<array>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<cctype>

using namespace std;

//defualt constructor
Puzzle::Puzzle()
{
	
}

// defualt deconstructor
Puzzle::~Puzzle()
{
}

// returns the value at a specific square. 
int Puzzle::get(int row, int col)
{
	int val = sudokuPuzzle[row][col].getValue();
	return val;
}

// Sets an int in a specific square. Is called by the input operator
bool Puzzle::set(int row, int col, int val)
{
	
	sudokuPuzzle[row][col].setValue(val);

	return true;
}

// returns the number of variable entries in the puzzle. 
int Puzzle::size()
{
	int count = 0;
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (sudokuPuzzle[row][col].getValue() == 0)
				count++;
		}
	}
	return count;
}

// returns the number of "empty" squares
int Puzzle::numempty()
{
	int count = 0;
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (sudokuPuzzle[row][col].getValue() == 0)
				count++;
		}
	}
	return count;
}

// returns if the number in the row and column is a fixed value
void Puzzle::setfixed(int row, int col, int val)
{
	if (val != 0)
		{
			sudokuPuzzle[row][col].fixedVal = true;
		}
		else
			sudokuPuzzle[row][col].fixedVal = false;
		
}

//used to print the puzzle after it is recieved by the istream operator.
void Puzzle::printPuzz()
{
	cout << " +-------+-------+-------+" << endl;
	for (int row = 0; row < 9; row++)
	{
		cout << " | ";
		for (int col = 0; col < 9; col++)
		{
			cout << sudokuPuzzle[row][col].getValue() << " ";
			if (!((col + 1) % 3))
				cout << "| ";
		}
		if (!((row + 1) % 3))
			cout << endl << " +-------+-------+-------+" << endl;
		else
			cout << endl;
	}
}

// returns true if there is a duplicate value in the row.
bool Puzzle::inRow(int row, int val)
{
	for (int col = 0; col < 9; col++)
	{
		if (sudokuPuzzle[row][col].getValue() == val)
		{
			return true;
		}
	}
	return false;
}

// returns true if there is a duplicate value in the column.
bool Puzzle::inCol(int col, int val)
{
	for (int row = 0; row < 9; row++)
	{
		if (sudokuPuzzle[row][col].getValue() == val)
		{
			return true;
		}
	}
	return false;
}

// returns true if there is a duplicate value in the 3x3 grid.
bool Puzzle::inBox(int row, int col, int val)
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (sudokuPuzzle[r + row][c + col].getValue() == val)
			{
				return true;
			}
		}
	}
	return false;
}

// returns the condition of the inBox, inCol, and inRow methods.
// which tells the solve method if a value is safe to assign. 
bool Puzzle::isSafe(int row, int col, int val)
{
	if (!inRow(row, val) && 
		!inCol(col, val) && 
		!inBox(row - row % 3, col - col % 3, val))
		return true;
	
	return false;
}


// Method for solving the puzzle in the 2D array. 
// it utilizes recursive functions and backtracking 
// in order to solve the puzzle.
bool Puzzle::solvePuzzle(int row, int col)
{
	if (col > 8) 
	{
		row ++;
		col = 0;
	}
			
	if (numempty() == 0) 
	{
		return true;
	}

	// Checking values 1 through 9
	for (int val = 1; val <= 9; val++)
	{
		// If this is fixed, just check the next Square
		if (sudokuPuzzle[row][col].readfixed() == true)
		{
			// returns the condition for backtracking to previous squares.
			return(solvePuzzle(row, col + 1));
		}

		// If this is a legal move AND the value at this position is not fixed...
		if (isSafe(row, col, val) && sudokuPuzzle[row][col].readfixed() == false)
		{
			sudokuPuzzle[row][col].setValue(val);
			if (solvePuzzle(row, col + 1))
			{
				return true;
			}
		} 					
	}
	// checks val 1-9 no solution found so returns false
	sudokuPuzzle[row][col].setValue(0);
	return false;
	
}


// Prints out the initial puzzle and then the completed form of the puzzle.
ostream& operator<<(ostream& output, Puzzle& p)
{
	cout << " +-------+-------+-------+" << endl;
	for (int row = 0; row < 9; row++)
	{
		cout << " | ";
		for (int col = 0; col < 9; col++)
		{
			cout << p.sudokuPuzzle[row][col].getValue() << " ";
			if (!((col + 1) % 3))
				cout << "| ";
		}
		if (!((row + 1) % 3))
			cout << endl << " +-------+-------+-------+" << endl;
		else
			cout << endl;
	}
	return output;
}

// Takes in 81 digits and assigns them to a 2D array of square objects.
istream& operator>>(istream& input, Puzzle& puz)
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9;)
		{
			char c = input.get();
			int val = c - '0';
			if (0 <= val && val <= 9)
			{
				puz.set(row, col, val);
				puz.setfixed(row, col, val);
				// If we have a valid char, increment 'col'
				col++;
			}
			// Otherwise, do nothing
		}
	}
	puz.printPuzz();
	puz.size();
	return input; 
}
