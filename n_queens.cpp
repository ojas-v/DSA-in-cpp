#include <iostream>
#include <vector>
#include <string>
using namespace std;

// n_queens.cpp
// Solves the N-Queens problem using simple backtracking.

// Check if it's safe to place a queen at row r, column c
bool isSafe(vector<string>& board, int r, int c, int size) {
    // Check all rows above in the same column
    for (int i = 0; i < r; i++) {
        if (board[i][c] == 'Q') return false;
    }
    // Check upper-left diagonal
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    // Check upper-right diagonal
    for (int i = r - 1, j = c + 1; i >= 0 && j < size; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

// Try to place queens row by row
void placeQueens(int row, int size, vector<string>& board, vector<vector<string>>& solutions) {
    if (row == size) {
        // All queens placed, save this board
        solutions.push_back(board);
        return;
    }

    // Try placing queen in each column of current row
    for (int col = 0; col < size; col++) {
        if (isSafe(board, row, col, size)) {
            board[row][col] = 'Q'; // place queen
            placeQueens(row + 1, size, board, solutions); // move to next row
            board[row][col] = '.'; // remove queen (backtrack)
        }
    }
}

// Main function to start solving
vector<vector<string>> solveNQueens(int size) {
    vector<vector<string>> solutions;  // stores all valid boards
    vector<string> board(size, string(size, '.')); // empty board
    placeQueens(0, size, board, solutions);
    return solutions;
}

// Print the board solutions
void printBoards(const vector<vector<string>>& solutions) {
    for (int i = 0; i < solutions.size(); i++) {
        vector<string> board = solutions[i];
        for (int j = 0; j < board.size(); j++) {
            string row = board[j];
            cout << row << "\n";
        }
        cout << "\n";
    }
}

int main() {
    int n = 4;
    cout << "All ways to place " << n << " queens on a " << n << "x" << n << " board:\n\n";
    vector<vector<string>> answers = solveNQueens(n);
    printBoards(answers);
    return 0;

// Important Words:
// - Row/Column: position on the board.
// - Diagonal: cells that lie in slant lines.
// - Backtracking: try a move, go deeper, and undo if it doesn't work.
// - Base Case: when we have placed queens on all rows.

}
