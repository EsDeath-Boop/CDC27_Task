class Solution {
public:
    // Function to check if the current move is valid
    bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited) {
        return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && visited[x][y] == 0);
    }

    // Recursive helper to explore all possible paths
    void solve(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited, string path, vector<string> &result) {
        // Base case: destination reached
        if (x == n - 1 && y == n - 1) {
            result.push_back(path);
            return;
        }

        // Mark current cell as visited
        visited[x][y] = 1;

        // Move in lexicographical order: D, L, R, U
        // Down
        if (isSafe(x + 1, y, n, maze, visited))
            solve(x + 1, y, n, maze, visited, path + 'D', result);

        // Left
        if (isSafe(x, y - 1, n, maze, visited))
            solve(x, y - 1, n, maze, visited, path + 'L', result);

        // Right
        if (isSafe(x, y + 1, n, maze, visited))
            solve(x, y + 1, n, maze, visited, path + 'R', result);

        // Up
        if (isSafe(x - 1, y, n, maze, visited))
            solve(x - 1, y, n, maze, visited, path + 'U', result);

        // Backtrack (unmark the current cell)
        visited[x][y] = 0;
    }

    // ✅ Function name changed to match GFG's expected signature
    vector<string> ratInMaze(vector<vector<int>> &maze) {
        int n = maze.size();
        vector<string> result;

        // If start or destination is blocked, no paths exist
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return result;

        vector<vector<int>> visited(n, vector<int>(n, 0));

        // Start exploring paths from (0, 0)
        solve(0, 0, n, maze, visited, "", result);

        // Sort paths lexicographically before returning
        sort(result.begin(), result.end());
        return result;
    }
};