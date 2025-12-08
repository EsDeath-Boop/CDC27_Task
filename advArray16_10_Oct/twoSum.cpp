#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int>ans;
            unordered_map<int,int>mp;
            for(int i = 0; i < nums.size(); i++) {
                int x = target - nums[i];
                if(mp.count(x)) {
                    ans.push_back(i);
                    ans.push_back(mp[x]);
                    return ans;
                } else {
                    mp[nums[i]] = i;
                }
            }
            return ans;
        }
    };
    return 0;
}