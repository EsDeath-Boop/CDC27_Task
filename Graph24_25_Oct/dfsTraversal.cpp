#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(vector<int>& ans,unordered_set<int>& vis,vector<vector<int>>& adj,int node) {
        ans.push_back(node);
        vis.insert(node);
        for(auto it : adj[node]) {
            if(!vis.count(it)) {
                dfs(ans,vis,adj,it);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        unordered_set<int>st;
        dfs(ans,st,adj,0);
        return ans;
    }
};