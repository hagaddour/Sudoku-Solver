#include "SudokuSolver.h"
#include <iostream>


SudokuSolver::SudokuSolver(std::vector<std::vector<int>> board): board(board)
    {
       rows.reserve(9);
       columns.reserve(9);
       square.reserve(81);
       std::set<int> temp;
    for (int i = 0; i < 9; ++i) {
            rows.emplace_back(temp);
            columns.emplace_back(temp);
        for (int j = 0; j < 9; j++) {
            square.emplace_back(temp);
        }
    }
       for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) continue;
            int sq = (i/3) * 3 + (j/3);
            rows[i].insert(board[i][j]);
            columns[j].insert(board[i][j]);
            square[sq].insert(board[i][j]);
        }
       }

    }
 
    bool SudokuSolver::solveSudoku(int y, int x)
    {
        if (y == 9) {return true;}
        int nx = (x+1) % 9;
        int ny = (nx == 0) ? y+1 : y;
        if (board[y][x] !=0) return solveSudoku(ny, nx);
        int sq = (y/3)*3 + (x/3);
        for (int i =1; i < 10; ++i) {
            if (rows[y].count(i) > 0 || columns[x].count(i) > 0
            || square[sq].count(i) > 0) continue;
            rows[y].insert(i);
            columns[x].insert(i);
            square[sq].insert(i);
            board[y][x] = i;
            if(solveSudoku(ny, nx)) return true;
            board[y][x] = 0;
            rows[y].erase(i);
            columns[x].erase(i);
            square[sq].erase(i);
        }
        return false;
    }
 
    void SudokuSolver::getBoard() {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
               std::cout << board[i][j] << " ";
            }
             std::cout << std::endl;
        }
    }
