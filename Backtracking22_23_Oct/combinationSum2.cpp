#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>subans,vector<int>& candi, int target,int idx) {
        if(target == 0) {
            ans.push_back(subans);
            return;
        }
        if(target<0)    return;
        if(idx == candi.size())    return;
        if(candi[idx]<=target) {
            subans.push_back(candi[idx]);
            helper(ans,subans,candi,target-candi[idx],idx+1);
            subans.pop_back();
        }
        int j = idx+1;
        while(j<candi.size() && candi[j] == candi[j-1])   j++;
        helper(ans,subans,candi,target,j);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>subans;
        helper(ans,subans,candidates,target,0);
        return ans;
    }
};