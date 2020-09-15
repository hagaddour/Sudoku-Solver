#ifndef _SUDOKUSOLVER_H_
#define _SUDOKUSOLVERH_
#include <vector>
#include <set>

class SudokuSolver
{
private:
    std::vector<std::vector<int>> board;
    std::vector<std::set<int>> rows;
    std::vector<std::set<int>> columns;
    std::vector<std::set<int>> square;

public:
    SudokuSolver(std::vector<std::vector<int>> board);
    bool solveSudoku(int y, int x);
    void getBoard();
};

#endif