class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Initializing hash table
        unordered_map<int, int> hash_table;

        // Finding result with Time Complexity O(n)
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums.at(i);
            // If this complement exists as a key in the hash table
            if (hash_table.count(complement)) {
                return {hash_table[complement], i};
            } else
                hash_table[nums.at(i)] = i; // If not, add it to the hash table
        }

        // No solution found
        return {};
    }
};
