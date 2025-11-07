#include <iostream>
#include <vector>
using namespace std;

/*
    Function: isSafe
    -----------------
    Checks whether the given cell (row, col) lies within
    the grid boundaries and is accessible (value = 1).
*/
bool isSafe(int row, int col, int N) {
    return (row >= 0 && col >= 0 && row < N && col < N);
}

/*
    Function: explorePaths
    -----------------------
    Recursively explores all possible unique paths from
    the current position (r, c) to the destination (destR, destC)
    using backtracking.

    Parameters:
        maze     → 2D grid representing open (1) and blocked (0) cells
        r, c     → current position
        destR, destC → destination coordinates
        visited  → tracks cells included in the current path
        pathCount → reference variable storing total number of valid paths
*/
void explorePaths(const vector<vector<int>>& maze,
                  int r, int c,
                  pair<int, int>& dest,
                  vector<vector<bool>>& visited,
                  int& pathCount)
{
    // If destination is reached, increment path counter
    if (r == dest.first && c == dest.second) {
        pathCount++;
        return;
    }

    // Mark this cell as visited
    visited[r][c] = true;

    int N = maze.size();

    // Move only if current cell is within bounds and open
    if (isSafe(r, c, N) && maze[r][c] == 1) {

        // ↓ Move Down
        if (r + 1 < N && !visited[r + 1][c])
            explorePaths(maze, r + 1, c, dest, visited, pathCount);

        // ↑ Move Up
        if (r - 1 >= 0 && !visited[r - 1][c])
            explorePaths(maze, r - 1, c, dest, visited, pathCount);

        // → Move Right
        if (c + 1 < N && !visited[r][c + 1])
            explorePaths(maze, r, c + 1, dest, visited, pathCount);

        // ← Move Left
        if (c - 1 >= 0 && !visited[r][c - 1])
            explorePaths(maze, r, c - 1, dest, visited, pathCount);
    }

    // Backtrack — unmark the current cell for other paths
    visited[r][c] = false;
}

/*
    Function: countUniquePaths
    --------------------------
    Wrapper function that initializes the 'visited' matrix
    and starts the recursive exploration from the source.
*/
int countUniquePaths(const vector<vector<int>>& maze,
                     pair<int, int>& start,
                     pair<int, int>& end)
{
    int N = maze.size();

    // Edge case: invalid grid or blocked start/destination
    if (N == 0 || maze[start.first][start.second] == 0 ||
        maze[end.first][end.second] == 0)
        return 0;

    int pathCount = 0;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    // Start the recursive search
    explorePaths(maze, start.first, start.second, end, visited, pathCount);

    return pathCount;
}

int main()
{
    // 4x4 maze grid: 1 = open path, 0 = blocked cell
    vector<vector<int>> maze = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1}
    };

    // Source and destination cells
    pair<int, int> start = {0, 0};
    pair<int, int> end = {3, 3};

    cout << "Total number of unique paths: "
         << countUniquePaths(maze, start, end) << endl;

    return 0;
}
