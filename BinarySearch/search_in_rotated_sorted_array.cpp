#include <iostream>
#include <vector>
using namespace std;

// Problem: Search in Rotated Sorted Array
// Pattern: Binary Search
// Approach:
// - At any point, one half of the array is sorted
// - Decide which half is sorted and check where the target lies
// Time: O(log n), Space: O(1)

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half sorted
        else {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
