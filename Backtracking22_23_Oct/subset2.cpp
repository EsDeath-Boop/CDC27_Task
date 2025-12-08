#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getAllComb(vector<int>& nums,vector<int>& ans,vector<vector<int>>& finalAns,int idx) {
        finalAns.push_back(ans);
        for(int i = idx;i<nums.size();i++) {
            if(i != idx && nums[i] == nums[i-1])    continue;
            ans.push_back(nums[i]);
            getAllComb(nums,ans,finalAns,i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>finalAns;
        sort(nums.begin(),nums.end());
        getAllComb(nums,ans,finalAns,0);
        return finalAns;
    }
};