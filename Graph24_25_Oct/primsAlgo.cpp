#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;
vector<list< pp > >graph;
void addEdge(int u,int v,int wt,bool bidirectional = true) {
    graph[u].push_back({v,wt});
    if(bidirectional) {
        graph[v].push_back({u,wt});
    }
}
ll prims(int src,int n) {
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    unordered_set<int>vis;
    unordered_map<int,int>mp;
    vector<int>par(n+1);
    for(int i = 1; i <= n; i++) {
        mp[i] = INT_MAX;
    }
    mp[src] = 0;
    pq.push({0,src});
    int totalCount = 0;
    int result = 0;
    while(totalCount < n) {
        auto curr = pq.top();
        if(vis.count(curr.second)) {
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        totalCount++;
        result += curr.first;
        pq.pop();
        for(auto neighbour : graph[curr.second]) {
            if(!vis.count(neighbour.first) && mp[neighbour.first] > neighbour.second) {
                pq.push({neighbour.second,neighbour.first});
                par[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    return result;
}
int main() {
    int n,m;
    cin>>n>>m;
    graph.resize(n+1,list<pp>());
    while(m--) {
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(u,v,wt);
    }
    int src;
    cin>>src;
    cout<<prims(src,n)<<endl;
    return 0;
}