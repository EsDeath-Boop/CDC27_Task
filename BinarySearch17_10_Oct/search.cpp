#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int lo = 0,hi = n-1;
            while(lo<=hi) {
                int mid = (lo+hi)/2;
                if(nums[mid] == target) return mid;
                if(nums[lo]<=nums[mid]) {    //left sorted
                    if(nums[lo]<=target && nums[mid]>=target) {
                        hi = mid-1;
                    } else {
                        lo = mid+1;
                    }
                } else {    //right sorted
                    if(nums[hi]>=target && nums[mid]<=target) {
                        lo = mid+1;
                    } else {
                        hi = mid-1;
                    }
                }
            }
            return -1;
        }
    };

    return 0;
}