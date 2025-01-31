class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
         int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        
        return -1;
    }

};