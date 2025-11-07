class Solution {
public:
    /*
        1. Use recursion to explore all possible subsets of the array.
        2. At each index, we have two choices:
            a) Include the current element in the subset (if it is ≤ remaining target).
            b) Exclude the current element and move to the next.
        3. Base cases:
            - If target becomes 0 → subset found → return true.
            - If we reach end of array (idx == n) → no subset → return false.
        4. If any recursive call returns true, propagate true upward.
        5. Otherwise, if no valid subset is found, return false.
    */
    
    bool findSubsets(int idx, int n, vector<int>& arr, int target) {
        // Base case: subset found
        if (target == 0) return true;
        // Base case: end of array, no subset
        if (idx == n) return false;

        // Include current element if it's not greater than remaining target
        if (arr[idx] <= target && findSubsets(idx + 1, n, arr, target - arr[idx])) 
            return true;

        // Exclude current element and check remaining elements
        return findSubsets(idx + 1, n, arr, target);
    }

    // Wrapper function to initiate recursion
    bool isSubsetSum(vector<int>& arr, int sum) {
        return findSubsets(0, arr.size(), arr, sum);
    }
};
