class Solution {
  public:
    /*
        1. Use a 1D dynamic programming array `dp` where dp[i] represents the number of ways to make sum `i`.
        2. Initialize dp[0] = 1 since there is exactly one way to make sum 0 (no coins).
        3. For each coin, iterate through all sums from coin value to target sum:
             dp[j] += dp[j - coin];
           This adds ways using the current coin.
        4. The final answer is dp[sum].
    */
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= sum; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[sum];
    }
};
