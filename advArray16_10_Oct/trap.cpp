#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            vector<int>prev(n);
            prev[0] = -1;
            int maxH = height[0];
            for(int i = 1; i < n; i++) {
                prev[i] = maxH;
                maxH = max(maxH,height[i]);
            }
            prev[n-1] = -1;
            maxH = height[n-1];
            for(int i = n-2; i >= 0; i--) {
                prev[i] = min(maxH,prev[i]);
                maxH = max(maxH,height[i]);
            }
            int water = 0;
            for(int i = 0; i < n; i++) {
                if(height[i] < prev[i]) {
                    water += (prev[i] - height[i]);
                }
            }
            for(int i = 0; i < n; i++) {
                cout<<prev[i]<<" ";
            }
            return water;
        }
    };

    return 0;
}