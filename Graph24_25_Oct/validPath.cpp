#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int>q;
        q.push(source);
        vector<bool>vis(n,false);
        unordered_map<int,vector<int>>adj;
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vis[source] = true;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(curr == destination) {
                return true;
            }
            for(auto it : adj[curr]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        return false;
    }
};