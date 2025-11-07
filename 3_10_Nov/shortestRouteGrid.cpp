#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Function: findTripletsWithSumLimit
    ----------------------------------
    Prints all unique triplets (a, b, c) from the array such that
    a + b + c <= given 'targetSum'.

    Approach:
    1. Sort the array to make the two-pointer approach possible.
    2. Fix one element (nums[i]) and then use two pointers (start, end)
       to find pairs whose sum with nums[i] is <= targetSum.
    3. When a valid triplet is found, all elements between start and end
       form valid triplets with nums[i].
*/
void findTripletsWithSumLimit(vector<int>& nums, int targetSum)
{
    // Sort the array to simplify pair searching
    sort(nums.begin(), nums.end());

    int n = nums.size();

    // Iterate through each element as the first element of the triplet
    for (int i = 0; i < n - 2; i++)
    {
        int start = i + 1;      // pointer just after current element
        int end = n - 1;        // pointer to the last element

        // Use two-pointer technique to find pairs with nums[i]
        while (start < end)
        {
            int total = nums[i] + nums[start] + nums[end];

            // If total is greater than target, move 'end' left
            if (total > targetSum)
            {
                end--;
            }
            else
            {
                // If total <= targetSum, then all elements between start and end
                // form valid triplets because the array is sorted
                for (int k = end; k > start; k--)
                {
                    cout << "(" << nums[i] << ", "
                         << nums[start] << ", "
                         << nums[k] << ") ";
                }

                // Move the start pointer forward to explore next combination
                start++;
            }
        }
    }
}

int main()
{
    // Example array of integers
    vector<int> arr = {2, 7, 4, 9, 5, 1, 3};

    // Given sum limit
    int target = 10;

    // Print all triplets satisfying the condition
    findTripletsWithSumLimit(arr, target);

    return 0;
}
