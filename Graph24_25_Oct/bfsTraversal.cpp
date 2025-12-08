#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        queue<int>q;
        q.push(0);
        unordered_set<int>st;
        st.insert(0);
        vector<int>ans;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto node : adj[curr]) {
                if(!st.count(node)) {
                    q.push(node);
                    st.insert(node);
                }
            }
        }
        return ans;
    }
};