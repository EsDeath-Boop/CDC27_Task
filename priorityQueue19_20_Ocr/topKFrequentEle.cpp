#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int>p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it : nums) {
            mp[it]++;
        }
        priority_queue<p,vector<p>,greater<>>pq;
        for(auto it : mp) {
            int freq = it.second;
            int x = it.first;
            pq.push({freq,x});
            if(pq.size() > k)   pq.pop();
        }
        vector<int>ans;
        while(pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};