class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();    // Size of the square matrix
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += mat[i][i];                  // Add primary diagonal element
            sum += mat[i][n - i - 1];          // Add secondary diagonal element
        }

        // If the matrix has an odd size, subtract the overlapping center element
        if (n % 2 == 1) {
            sum -= mat[n / 2][n / 2];
        }

        return sum;
    }
};