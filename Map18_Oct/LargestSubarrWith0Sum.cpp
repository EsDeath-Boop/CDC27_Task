#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        int maxLen = 0;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(sum == 0) {
                maxLen = i+1;
            } else if(mp.count(sum)) {
                maxLen = max(maxLen,i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};