#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int minIndex = 0, maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex]) 
                minIndex = i;
            if (nums[i] > nums[maxIndex]) 
                maxIndex = i;
        }

        int leftIndex = min(minIndex, maxIndex);
        int rightIndex = max(minIndex, maxIndex);

        int front = rightIndex + 1;
        int back = n - leftIndex;
        int both = (leftIndex + 1) + (n - rightIndex);

        return min({front, back, both});
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.minimumDeletions(nums);
    cout << "Minimum deletions required: " << result << "\n";

    return 0;
}
