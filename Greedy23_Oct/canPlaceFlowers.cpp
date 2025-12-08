#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            bool left = i == 0 || nums[i-1] == 0;
            bool right = i == nums.size()-1 || nums[i+1] == 0;
            if(left && right && !nums[i]) {
                nums[i] = 1;
                ans++;
            }
        }
        return ans >= n;
    }
};