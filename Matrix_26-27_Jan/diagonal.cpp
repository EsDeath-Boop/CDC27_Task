class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();       // Number of rows
        int n = mat[0].size();    // Number of columns
        vector<int> result;       // To store the diagonal order
        result.reserve(m * n);    // Pre-allocate space for efficiency
        
        int row = 0, col = 0;
        bool upward = true;       // Direction: true -> upward, false -> downward
        
        while (result.size() < m * n) {
            result.push_back(mat[row][col]);
            
            if (upward) {
                if (col == n - 1) {    // Hit the right boundary
                    row++;
                    upward = false;
                } else if (row == 0) { // Hit the top boundary
                    col++;
                    upward = false;
                } else {               // Move up diagonally
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) {    // Hit the bottom boundary
                    col++;
                    upward = true;
                } else if (col == 0) { // Hit the left boundary
                    row++;
                    upward = true;
                } else {               // Move down diagonally
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
};