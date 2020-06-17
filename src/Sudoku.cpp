#include "Sudoku.h"
#include <iostream>
#include <vector>

using namespace std;
using std::vector;

Sudoku::Sudoku(vector<vector<int>> _sudokuTable)
    : sudokuTable(_sudokuTable) {};

void Sudoku::operator()() {
    
    solve(1, 0);
    showResult();

};

bool Sudoku::solve(int val, int row) {

    if (val == 10)
        return true;

    if (row == 9)
        return solve(val + 1, 0);

    if (isAlreadyRow(val, row))
        return solve(val, row + 1);
    
    for (int col = 0; col < COLUMNS; col++) {
        if (isValid(val, row, col)) {
            sudokuTable[row][col] = val;
            if (solve(val, row + 1)) {
                std::cout << "Value " << val << " goes to row " << row << " and column " << col << std::endl;
                return true;
            }
            sudokuTable[row][col] = 0;
        }
    }
    
    return false;
};

bool Sudoku::isAlreadyRow(int val, int row) {
    for (int element : sudokuTable[row]) {
        if (val == element)
            return true;
    }
    return false;
};

bool Sudoku::isValid(int val, int row, int column) {
    // Verifies empty cell
    if (sudokuTable[row][column] != 0)
        return false;

    // Row verification changing column
    for (int col = 0; col < COLUMNS; col++) {
        if (sudokuTable[row][col] == val) {
            return false;
        }
    }

    // Column verification changing row
    for (int row_ = 0; row_ < ROWS; row_++) {
        if (sudokuTable[row_][column] == val) {
            return false;
        }
    }

    // 3x3 square verification defining interval - This could be dfined inside for loops
    for (int row_ = 3 * (row / 3); row_ < 3 * (row / 3 + 1); row_++) {
        for (int col = 3 * (column / 3); col < 3 * (column / 3 + 1); col++) {
            if (sudokuTable[row_][col] == val)
                return false;
        }
    }

    // returns true if none of the above verifications failed
    return true;
};

void Sudoku::showResult() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << sudokuTable[i][j] << " ";
            if ((j + 1) % 3 == 0 && j != 8)
                std::cout << " | ";
        }
        std::cout << std::endl;
        if ((i + 1) % 3 == 0 && i != 8)
            std::cout << "-----------------------" << std::endl;
    }
};