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
unordered_map<int,int> dijkstra(int src,int n) {
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    unordered_set<int>vis;
    unordered_map<int,int>mp;
    vector<int>via(n+1);
    for(int i = 0; i < n; i++) {
        mp[i] = INT_MAX;
    }
    mp[src] = 0;
    pq.push({0,src});
    while(!pq.empty()) {
        auto curr = pq.top();
        if(vis.count(curr.second)) {
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        pq.pop();
        for(auto neighbour : graph[curr.second]) {
            if(!vis.count(neighbour.first) && mp[neighbour.first] > mp[curr.second] + neighbour.second) {
                pq.push({mp[curr.second] + neighbour.second,neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = mp[curr.second] + neighbour.second;
            }
        }
    }
    return mp;
}
int main() {
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    while(m--) {
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(u,v,wt);
    }
    int src;
    cin>>src;
    unordered_map<int,int>shortestPath = dijkstra(src,n);
    cout<<"Enter des"<<endl;
    // int des;
    // cin>>des;
    // cout<<shortestPath[des]<<endl;
    for(auto p : shortestPath) {
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}