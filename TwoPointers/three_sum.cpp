#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: 3Sum
// Pattern: Sorting + Two Pointers
// Approach:
// 1. Sort the array.
// 2. Fix one element and use two pointers to find pairs with sum = -fixed.
// 3. Skip duplicates to avoid repeated triplets.
// Time Complexity: O(n^2)
// Space Complexity: O(1) extra (excluding output)

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates

        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return result;
}
