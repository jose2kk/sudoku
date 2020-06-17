#include <iostream>
#include <vector>
#include "Sudoku.cpp"

using namespace std;

int main() {

    vector<vector<int>> table = {
        {6, 4, 0, 0, 1, 3, 9, 0, 0},
        {1, 0, 0, 0, 2, 6, 4, 0, 0},
        {0, 2, 9, 0, 4, 5, 7, 0, 0},
        {0, 0, 2, 0, 0, 0, 8, 3, 0},
        {8, 6, 0, 0, 3, 7, 0, 1, 9},
        {7, 0, 0, 2, 0, 9, 0, 0, 0},
        {0, 0, 1, 3, 0, 0, 6, 9, 0},
        {9, 3, 6, 4, 0, 8, 0, 2, 0},
        {0, 0, 5, 0, 0, 0, 0, 0, 0}
    };
    
    Sudoku SudokuProblem(table);
    SudokuProblem();
    return 0;
};