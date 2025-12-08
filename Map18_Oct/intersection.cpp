#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            vector<int> ans;
            unordered_map<int,int>mp;
            for(auto it : nums1)    mp[it]++;
            for(auto it: nums2) {
                if(mp.count(it)) {
                    ans.push_back(it);
                    mp.erase(it);
                }
            }
            return ans;
        }
    };

    return 0;
}