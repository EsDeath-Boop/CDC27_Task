#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combi(int n,int k,vector<int>& ans,vector<vector<int>>&finalAns,int idx) {
        if(ans.size() == k) {
            finalAns.push_back(ans);
            return;
        }
        for(int i = idx;i<=n;i++) {
            ans.push_back(i);
            combi(n,k,ans,finalAns,i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        vector<vector<int>>finalAns;
        combi(n,k,ans,finalAns,1);
        return finalAns;
    }
};