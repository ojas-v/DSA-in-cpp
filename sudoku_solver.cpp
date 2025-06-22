#include <iostream>
#include <vector>
using namespace std;

// sudoku_solver.cpp
// Solve a standard 9x9 Sudoku puzzle using backtracking.

// Check if we can place 'num' at board[row][col]
bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return false; // check row
        if (board[i][col] == num) return false; // check column
        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;
        if (board[boxRow][boxCol] == num) return false; // check 3x3 box
    }
    return true;
}

// Main solving function
bool solveSudokuHelper(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudokuHelper(board)) return true; // recurse
                        board[row][col] = '.'; // backtrack
                    }
                }
                return false; // no valid number found
            }
        }
    }
    return true; // solved
}

void solveSudoku(vector<vector<char>>& board) {
    solveSudokuHelper(board);
}

// Print the board
void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);
    cout << "Solved Sudoku Board:\n";
    printBoard(board);
    return 0;

// Important Terms:
// - Grid: 9x9 board
// - Cell: a single box in the grid
// - Backtracking: try a number, go deeper, undo if not working
// - Base Case: when all cells are filled correctly
}
