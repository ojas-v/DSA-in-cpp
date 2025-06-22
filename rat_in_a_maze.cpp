#include <iostream>
#include <vector>
#include <string>
using namespace std;

// rat_maze.cpp
// Find all paths for a rat to move from top-left to bottom-right in a maze.

bool isSafe(int row, int col, int n, vector<vector<int>>& maze, vector<vector<int>>& visited) {
    return (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1 && visited[row][col] == 0);
}

void findPaths(int row, int col, int n, vector<vector<int>>& maze, vector<vector<int>>& visited,
               string path, vector<string>& paths) {
    if (row == n - 1 && col == n - 1) {
        paths.push_back(path);
        return;
    }

    visited[row][col] = 1; // mark cell as visited

    // Move Down
    if (isSafe(row + 1, col, n, maze, visited))
        findPaths(row + 1, col, n, maze, visited, path + 'D', paths);

    // Move Left
    if (isSafe(row, col - 1, n, maze, visited))
        findPaths(row, col - 1, n, maze, visited, path + 'L', paths);

    // Move Right
    if (isSafe(row, col + 1, n, maze, visited))
        findPaths(row, col + 1, n, maze, visited, path + 'R', paths);

    // Move Up
    if (isSafe(row - 1, col, n, maze, visited))
        findPaths(row - 1, col, n, maze, visited, path + 'U', paths);

    visited[row][col] = 0; // backtrack (unmark cell)
}

vector<string> solveMaze(vector<vector<int>>& maze) {
    int n = maze.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> allPaths;

    if (maze[0][0] == 1)
        findPaths(0, 0, n, maze, visited, "", allPaths);

    return allPaths;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = solveMaze(maze);

    cout << "All paths from start to end:\n";
    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i] << "\n";
    }

    return 0;

// Important Terms:
// - Maze: grid of 0s and 1s.
// - Path: a sequence of moves from start to end.
// - Backtracking: try a move, go forward, undo if stuck.
// - Visited: keep track of where we already went.
}
