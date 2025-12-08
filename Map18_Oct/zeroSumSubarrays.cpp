#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        unordered_map<int,int>mp;
        int count = 0;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(sum == 0)    count++;
            if(mp.count(sum)) {
                count += mp[sum];
            }
            mp[sum]++;
        }
        return count;
    }
};