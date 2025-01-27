class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();        // Number of rows in the original matrix
        int n = mat[0].size();     // Number of columns in the original 
        
        if (m * n != r * c) {      // Check if reshape is possible
            return mat;            // Return original matrix if not possible
        }
        
        vector<vector<int>> reshaped(r, vector<int>(c));
        int row = 0, col = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                reshaped[row][col] = mat[i][j];
                col++;
                if (col == c) {    // Move to the next row
                    col = 0;
                    row++;
                }
            }
        }
        
        return reshaped;
    }
};