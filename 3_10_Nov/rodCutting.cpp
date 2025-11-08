/*
basic approach recurssion

class Solution {
  public:
    
    Algorithm: Rod Cutting (Recursive Approach)
    --------------------------------------------
    Objective:
        Given a rod of length N and an array price[] where price[i] represents
        the price of a rod of length (i+1), determine the maximum obtainable value
        by cutting up the rod and selling the pieces.
        

    int solve(int i, vector<int>& price) {
        if (i == 0) return 0;
        int ans = 0;
        for (int j = 1; j <= i; j++) {
            ans = max(ans, price[j - 1] + solve(i - j, price));
        }
        return ans;
    }

    int cutRod(vector<int>& price) {
        int n = price.size();
        return solve(n, price);
    }
};
*/

// optimal sol: dp

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }

        return dp[n];
    }
};



