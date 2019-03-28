/* This is the interface for the puzzle class. 
Incorporates square type for the 2D array. 

*/

#pragma once
#include<iostream>
#include"square.h"

using namespace std;

class Puzzle
{
	
public:
	
	// the 2D array of Square objects that is created through 
	// the istream operator. 
	Square sudokuPuzzle[9][9];
	
	//constructor 
	Puzzle();
	//deconstructor 
	~Puzzle();
	
	//retrieves value in the square
	int get(int row, int val);
	// sets the value in the square
	bool set(int row, int col, int val);
	// retrieves the number of veriable entries in the puzzle
	int size();
	// returns the number of empty squares in the puzzle
	int numempty();
	
	// returns whether the value at the specified location is fix or not
	void setfixed(int row, int col, int val);

	// prints the puzzle from the 2D array
	void printPuzz();
	
	//***************************************
	// The methods for finding duplicates.
	//***************************************
	// looks for duplicate values in a row 
	// returns true if dup false if non dup
	bool inRow(int row, int val);
	// looks for duplicate values in a col
	// returns true if dup false if non dup
	bool inCol(int col, int val);
	// looks for duplicate values in a box
	// returns true if dup false if non dup
	bool inBox(int row, int col, int val);
	// returns the conditions for each of the three above methods
	// returns true if dup false if non dup
	bool isSafe(int row, int col, int val);

	// this is the recursive method for solving the sudoku puzzle
	// accepts an int row and col parameters
	// returns true if successful false if not successful
	// Fucntions called:
	// inBox, isSafe, inCol, inRow, readfixed
	bool solvePuzzle(int row, int col);

	// Prints out the result of the SolvePuzzle method. 
	friend ostream& operator<<(ostream& output, Puzzle& num);

	// Fills the sudoku puzzle from cin and places it in the 
	// 2D Square array. 
	friend istream& operator>>(istream& input, Puzzle& num);

	
		
};

