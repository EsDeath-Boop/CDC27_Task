#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
    
        bool canPlace(vector<int> &a, int k, int dist) {
            int cnt = 1, last = a[0];
            for (int i = 1; i < a.size(); i++) {
                if (a[i] - last >= dist) {
                    cnt++;
                    last = a[i];
                    if (cnt == k) return true;
                }
            }
            return false;
        }

        int aggressiveCows(vector<int> &stalls, int k) {
            sort(stalls.begin(), stalls.end());
            int low = 1, high = stalls.back() - stalls.front(), ans = 0;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (canPlace(stalls, k, mid)) {
                    ans = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return ans;
        }
    };


    return 0;
}