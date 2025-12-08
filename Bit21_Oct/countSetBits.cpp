#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSetBits(int n) {
        // code here
        int count = 0;
        for(int i = 1; i <= n; i++) {
            int x = i;
            while(x) {
                x = (x & (x-1));
                count++;
            }
        }
        return count;
    }
};
