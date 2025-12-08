#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combi(vector<int>& candidates, int target,vector<int>&ans,vector<vector<int>>& finalAns,int idx) {
        if(target == 0) {
            finalAns.push_back(ans);
            return;
        }
        if(target<0)    return;
        if(idx == candidates.size())    return;
        if(candidates[idx]<=target) {
            ans.push_back(candidates[idx]);
            combi(candidates,target-candidates[idx],ans,finalAns,idx);
            ans.pop_back();
        }
        combi(candidates,target,ans,finalAns,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        vector<vector<int>>finalAns;
        combi(candidates,target,ans,finalAns,0);
        return finalAns;
    }
};