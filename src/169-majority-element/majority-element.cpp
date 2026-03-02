class Solution {
public:
    // Boyer-Moore Majority Voting Algorithm.
    // Time complexity O(n). Space complexity 0(1).
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int votes = 0;

        for (const auto& n : nums) {
            if (votes == 0) candidate = n; 
            votes += (n == candidate) ? 1 : -1;
        }

        return candidate;

    }
};
