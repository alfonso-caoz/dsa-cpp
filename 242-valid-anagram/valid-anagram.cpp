class Solution {
public:
    // Time Complexity O(n). Space Complexity O(1). ***Avoid using find and count inside of a for loop, Time Complexity can be messed up.
    // operator[]: if the key does not exist, it inserts it with a default value for int or double: 0. Other types structure problematic.
    // Hash maps are equal if have same key-value pairs, despite the order.
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> sHashCount;
        unordered_map<char, int> tHashCount;

        for (int i = 0; i < s.length(); ++i) {
            sHashCount[s[i]] = sHashCount[s[i]] + 1; 
            tHashCount[t[i]] = tHashCount[t[i]] + 1;
        }

        return sHashCount == tHashCount;

    }
};
