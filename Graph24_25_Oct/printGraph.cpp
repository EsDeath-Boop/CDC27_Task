#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>ans;
        for(int i = 0; i < V; i++) {
            vector<int>temp;
            for(int j = 0; j < adj[i].size(); j++) {
                temp.push_back(adj[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};