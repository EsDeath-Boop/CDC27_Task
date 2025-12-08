#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xOr = 0;
        for(int x : nums) {
            xOr ^= x;
        }
        return xOr;
    }
};