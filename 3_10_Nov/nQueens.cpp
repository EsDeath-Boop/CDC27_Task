#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Recursive utility function that tries to place queens column by column
void nQueenUtil(int col, int n, vector<int> &board,
                vector<bool> &rows, vector<bool> &diag1,
                vector<bool> &diag2, vector<vector<int>> &solutions) {

    // Base case: if all queens are placed, store the configuration
    if (col > n) {
        solutions.push_back(board);
        return;
    }

    // Try placing a queen in every row for this column
    for (int row = 1; row <= n; ++row) {

        // Check if placing a queen at (row, col) is safe:
        // - Row must not have another queen
        // - Major diagonal (row + col) must be free
        // - Minor diagonal (row - col + n) must be free
        if (!rows[row] && !diag1[row + col] && !diag2[row - col + n]) {

            // Place the queen and mark the row and diagonals as occupied
            rows[row] = diag1[row + col] = diag2[row - col + n] = true;
            board.push_back(row);

            // Move to the next column
            nQueenUtil(col + 1, n, board, rows, diag1, diag2, solutions);

            // Backtrack: remove the queen and unmark the row and diagonals
            board.pop_back();
            rows[row] = diag1[row + col] = diag2[row - col + n] = false;
        }
    }
}

// Initializes helper data structures and starts solving the N-Queens problem
vector<vector<int>> nQueen(int n) {
    vector<vector<int>> solutions;     // Stores all valid board configurations
    vector<int> board;                 // Stores the current placement of queens

    vector<bool> rows(n + 1, false);   // Tracks which rows already have queens
    vector<bool> diag1(2 * n + 1, false); // Tracks major diagonals (row + col)
    vector<bool> diag2(2 * n + 1, false); // Tracks minor diagonals (row - col + n)

    // Start placing queens from the first column
    nQueenUtil(1, n, board, rows, diag1, diag2, solutions);
    return solutions;
}

// Driver function to display all possible solutions
int main() {
    int n = 4;
    vector<vector<int>> solutions = nQueen(n);

    // Print each solution in compact form
    for (int i = 0; i < solutions.size(); i++) {
        cout << "[";
        for (int j = 0; j < n; ++j) {
            cout << solutions[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << "]\n";
    }
    return 0;
}
