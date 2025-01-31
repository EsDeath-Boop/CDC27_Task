class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

    for (int num : nums1) {
        int index = -1;
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] == num) {
                index = i;
                break;
            }
        }

        int nextGreater = -1;
        for (int i = index + 1; i < nums2.size(); i++) {
            if (nums2[i] > num) {
                nextGreater = nums2[i];
                break;
            }
        }
        result.push_back(nextGreater);
    }

    return result;
    }
};