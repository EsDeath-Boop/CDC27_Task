#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // The API isBadVersion is defined for you.
    // bool isBadVersion(int version);


    class Solution {
    public:
        int firstBadVersion(int n) {
            long long lo = 0,hi = n;
            long long ans = INT_MAX;
            while(lo<=hi) {
                long long mid = (lo+hi)/2;
                if(isBadVersion(mid)) {
                    ans = min(ans,mid);
                    hi = mid-1;
                }
                else lo = mid+1;
            }
            return ans;
        }
    };

    return 0;
}