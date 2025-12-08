#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> nxt;  // maps value → next greater value
            stack<int> st;                // decreasing stack

            // Process nums2 to build next greater mapping
            for (int num : nums2) {
                while (!st.empty() && num > st.top()) {
                    nxt[st.top()] = num;  // found next greater
                    st.pop();
                }
                st.push(num);
            }

            // Remaining elements have no next greater
            while (!st.empty()) {
                nxt[st.top()] = -1;
                st.pop();
            }

            // Build result for nums1
            vector<int> ans;
            ans.reserve(nums1.size());
            for (int x : nums1) ans.push_back(nxt[x]);

            return ans;
        }
    };


    return 0;
}