#include <cmath> // std::abs()

class Solution {
public:
    // Time Complexity O(n) [O(2*n)]. Space Complexity O(1).
    // Note: Avoid using set, not possible to iterate by position, just by elements.
    // Avoid count(), find() or other, those tend to be a time complexity of O(logn).
    // If it is required, abs of all elements in nums to reset it back as it entered the function.
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;

        // Use elements as "index" to mark the element in that new "index" as found with a -.
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1; // Abs: If that element (used as index) was repeated (-X * -X). Zero based index.
            if (nums[index] > 0) nums[index] *= -1;
        }

        // All elements not marked with a -. i with positive elements, that operator i is missing in the array.
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) result.push_back(i + 1); // Zero based index.
        }

        return result;
    }
};
