#include <vector>
#include "SudokuSolver.h"
#include <iostream>
#include <set>

int main()
{
	std::vector<std::vector<int>> game {
	    {3,8,5,0,0,0,0,0,0},
		{9,2,1,0,0,0,0,0,0},
		{6,4,7,0,0,0,0,0,0},
		{0,0,0,1,2,3,0,0,0},
		{0,0,0,7,8,4,0,0,0},
		{0,0,0,6,9,5,0,0,0},
		{0,0,0,0,0,0,8,7,3},
		{0,0,0,0,0,0,9,6,2},
		{0,0,0,0,0,0,1,4,5}};
	SudokuSolver solver = SudokuSolver(game);
	solver.solveSudoku(0,0);
	solver.getBoard();
}
