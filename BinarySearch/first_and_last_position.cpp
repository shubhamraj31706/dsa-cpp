#include <iostream>
#include <vector>
using namespace std;

// Problem: Find First and Last Position of Element in Sorted Array
// Pattern: Binary Search (Lower Bound & Upper Bound)
// Approach:
// 1. Use binary search to find the first occurrence (lower bound).
// 2. Use binary search to find the last occurrence (upper bound - 1).
// Time Complexity: O(log n)
// Space Complexity: O(1)

int findFirst(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            high = mid - 1;   // move left
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int findLast(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            low = mid + 1;   // move right
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {findFirst(nums, target), findLast(nums, target)};
}
