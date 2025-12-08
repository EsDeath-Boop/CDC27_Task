#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)  return nums;
        vector<int>ans;
        deque<int>dq;
        for(int i = 0; i < nums.size(); i++) {
            while(dq.size() > 0 && nums[i] > nums[dq.back()])   dq.pop_back();
            dq.push_back(i);
            int j = i - k + 1;
            if(j > dq.front())  dq.pop_front();
            if(i >= k-1)    ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};