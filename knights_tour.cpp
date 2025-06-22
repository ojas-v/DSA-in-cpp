#include <iostream>
using namespace std;

// knights_tour.cpp
// Solve the Knight's Tour problem using simple backtracking

const int SIZE = 8; // 8x8 chessboard
int board[SIZE][SIZE];

// 8 possible knight moves
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Check if move is inside board and cell is not visited
bool isSafe(int row, int col) {
    return (row >= 0 && col >= 0 && row < SIZE && col < SIZE && board[row][col] == -1);
}

// Try to move the knight step by step
bool solveKnightTour(int row, int col, int step) {
    if (step == SIZE * SIZE) return true; // visited all cells

    for (int i = 0; i < 8; i++) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        if (isSafe(newRow, newCol)) {
            board[newRow][newCol] = step; // mark step
            if (solveKnightTour(newRow, newCol, step + 1)) return true; // next step
            board[newRow][newCol] = -1; // backtrack
        }
    }
    return false; // no valid move
}

// Print the chessboard
void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    // Initialize all cells to -1 (not visited)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = -1;
        }
    }

    // Start from top-left corner
    board[0][0] = 0;

    if (solveKnightTour(0, 0, 1)) {
        cout << "Knight's Tour solution:\n";
        printBoard();
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
