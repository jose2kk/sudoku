#ifndef Sudoku_h
#define Sudoku_h

#include <vector>

using std::vector;

class Sudoku {

    const int COLUMNS = 9;
    const int ROWS = 9;

    vector<vector<int>> sudokuTable;

public:
    Sudoku(vector<vector<int>> _sudokuTable);
    void operator()();

private:
    void showResult();
    bool solve(int val, int row);
    bool isValid(int val, int row, int column);
    bool isAlreadyRow(int val, int row);
};

#endif