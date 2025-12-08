#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        int maxArea(vector<int>& height) {
            int n = height.size();
            int lp = 0 ,rp = n-1;
            int area = 0;
            int maxwater = 0;
            while(lp<rp){
                int width = rp - lp;
                area = width*min(height[lp],height[rp]);
                maxwater = max(maxwater,area);
                if(height[lp]<height[rp])   lp++;
                else        rp--;
            }
            return maxwater;
        }
    };

    return 0;
}