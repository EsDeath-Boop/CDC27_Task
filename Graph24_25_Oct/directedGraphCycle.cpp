#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecStack) {
        visited[node] = true;
        inRecStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, inRecStack))
                    return true;  // cycle found
            } 
            else if (inRecStack[neighbor]) {
                // Found a back edge
                return true;
            }
        }

        inRecStack[node] = false; // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(V, false);
        vector<bool> inRecStack(V, false);

        // Run DFS for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, inRecStack))
                    return true;
            }
        }
        return false;
    }
};
