class Solution {
public:
    int romanToInt(string s) {

        // Hash table
        unordered_map<char, int> hash_table = { {'I', 1}, 
                                                {'V', 5}, 
                                                {'X', 10}, 
                                                {'L', 50}, 
                                                {'C', 100}, 
                                                {'D', 500}, 
                                                {'M', 1000} };

        int result = 0; // Result initialized

        // Time complexity O(n) and Space complexity O(1)
        for (int i = 0; i < s.length() - 1; ++i) {
            // (i) value greater than or Equal to (i+1) value: Addition
            if (hash_table[s.at(i)] >= hash_table[s.at(i + 1)]) {
                result += hash_table[s.at(i)]; // Assigning a (+) to the current value
            } else {
            // (i) value less than (i+1) value: Substraction 
                result -= hash_table[s.at(i)]; // Assigning a (-) to the current value
            }
        }

        return result + hash_table[s[s.length() - 1]]; // Adding last string element skipped from the for loop

    }
};
