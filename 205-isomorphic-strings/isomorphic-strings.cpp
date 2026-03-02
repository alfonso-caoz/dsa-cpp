class Solution {
public:
    // Time Complexity O(n) [n = s.length() = t.length()]. 
    // Space Complexity O(1) [Any valid ASCII character, which is a finite amount of elements].
    // 128 standard ASCII characters. 256 extended ASCII characters. 2 Hash maps implemented: Constant Space.
    // Considering constraints, to not validate if s and t are the same length, or any of them is empty.
    // Another approach: 
    // 1 Hash map, but 2 for loops required. One to iterate s, another to check if s[i] (keys) exists in all Values (t).: s "bd" t: "bb",
    // count() and find() operates just over keys, not values of a hash map.
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> maps;
        unordered_map<char, char> mapt;

        for (int i = 0; i < s.length(); ++i) {
            if (maps.count(s[i])!=0 && maps[s[i]]!=t[i]) return false;
            if (mapt.count(t[i])!=0 && mapt[t[i]]!=s[i]) return false;
            maps[s[i]] = t[i];
            mapt[t[i]] = s[i];
        }

        return true;

    }
};
