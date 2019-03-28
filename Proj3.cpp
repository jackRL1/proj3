/* Jack Linderoth (1211184)
CSS 301 Program 3. 
11/15/2017 

Shout out to my mom who always believes in me. 

The program is designed to utilize two classes the square and puzzle class 
along with a driver to solve sudoku puzzles. It takes in 81 digits and 
assigns them to a 2D array. From there it uses backtracking and recursion to 
complete a sudoku puzzle and Print out Success. 
If it cannot be completed it will return unsuccessful.

this Class relies on the square.cpp square.h
as well as puzzle.cpp and puzzle.h in order to operate correctly

*/


#include<istream>
#include<ostream>
#include"puzzle.h"
#include"square.h"
#include<array>
#include<string>

using namespace std;

// this is the main driver for the program
int main()
{

	Puzzle num; // initializes the Puzzle object

	cin >> num; // takes input through cin and signs it to the puzzle object

	// The output logic for the Successful completion or if there is no solution available
	if (num.solvePuzzle(0, 0) == 0)
	{
		cout << "No Solution Available" << endl;
	}
	if (num.solvePuzzle(0, 0) == 1)
	{
		cout << "SUCCESS!!" << endl;
	}
	
	cout << num << endl; // outputs the solved puzzle or states it is not solveable 

	return 0;
}
