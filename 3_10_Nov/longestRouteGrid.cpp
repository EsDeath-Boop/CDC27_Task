#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Function: isValidMove
    ----------------------
    Checks whether the next cell (row, col) can be visited.

    A move is valid if:
    1. It lies within the matrix boundaries.
    2. The cell value is 1 (open path).
    3. The cell has not been visited yet.
*/
bool isValidMove(const vector<vector<int>>& grid, const vector<vector<bool>>& visited,
                 int row, int col)
{
    int rows = grid.size();
    int cols = grid[0].size();

    return (row >= 0 && row < rows && col >= 0 && col < cols &&
            grid[row][col] == 1 && !visited[row][col]);
}

/*
    Recursive Function: exploreLongestRoute
    ---------------------------------------
    Finds the longest path from (r, c) to the destination (destR, destC).

    Parameters:
        grid     → input matrix of 0s (blocked) and 1s (open)
        visited  → tracks whether a cell is part of the current path
        r, c     → current cell coordinates
        destR, destC → destination cell coordinates
        distance → length of current path so far
        maxDist  → stores the maximum path length found (by reference)
*/
void exploreLongestRoute(const vector<vector<int>>& grid, vector<vector<bool>>& visited,
                         int r, int c, int destR, int destC,
                         int distance, int& maxDist)
{
    // If current cell is blocked, return immediately
    if (grid[r][c] == 0)
        return;

    // If destination is reached, update max distance
    if (r == destR && c == destC)
    {
        maxDist = max(maxDist, distance);
        return;
    }

    // Mark this cell as visited to avoid revisiting in current path
    visited[r][c] = true;

    // Explore all 4 possible directions (Down, Right, Up, Left)
    int rowMoves[] = {1, 0, -1, 0};
    int colMoves[] = {0, 1, 0, -1};

    for (int dir = 0; dir < 4; dir++)
    {
        int nextR = r + rowMoves[dir];
        int nextC = c + colMoves[dir];

        if (isValidMove(grid, visited, nextR, nextC))
        {
            exploreLongestRoute(grid, visited, nextR, nextC, destR, destC,
                                distance + 1, maxDist);
        }
    }

    // Backtrack: unmark the current cell before returning
    visited[r][c] = false;
}

/*
    Function: longestPathLength
    ----------------------------
    Wrapper function that initializes required variables and
    calls the recursive search for the longest route.
*/
int longestPathLength(vector<vector<int>>& grid, pair<int, int> start,
                      pair<int, int> end)
{
    // Check for invalid input or blocked start/destination
    if (grid.empty() || grid[start.first][start.second] == 0 ||
        grid[end.first][end.second] == 0)
        return -1;

    int rows = grid.size(), cols = grid[0].size();

    // Visited matrix to track cells already in current path
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int maxDist = 0;
    exploreLongestRoute(grid, visited, start.first, start.second,
                        end.first, end.second, 0, maxDist);

    return maxDist;
}

int main()
{
    // Matrix representing open (1) and blocked (0) cells
    vector<vector<int>> grid =
    {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
        {1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0}
    };

    // Define starting and destination points
    pair<int, int> start = {0, 0};
    pair<int, int> end = {5, 7};

    // Call the function and display the result
    int result = longestPathLength(grid, start, end);
    cout << "The longest possible path length is: " << result << endl;

    return 0;
}
 