#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        return ((n >> k) & 1);  //right shift n k times and take and with 1 will result the ans
        // return ((1 << k) & n);   // left shift 1 k times and take and with n will result the ans
    }
};