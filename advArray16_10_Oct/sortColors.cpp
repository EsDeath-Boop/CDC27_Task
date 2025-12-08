#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int low = 0;
            int mid = 0;
            int high = n-1;
            for(int i = 0; i<n ; i++) {
                if(nums[mid] == 2) {
                    nums[mid] = nums[high];
                    nums[high] = 2;
                    high--;
                }
                else if(nums[mid] == 0) {
                    nums[mid] = nums[low];
                    nums[low] = 0;
                    mid++;
                    low++;
                }
                else mid++;
            }
        }
    };
    return 0;
}