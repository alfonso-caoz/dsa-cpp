class Solution {
public:
    // Time Complexity O(n) [for: O(n) + while (1 long word): O(n/2)]. Space Complexity O(1): s reversed in place. Also: https://www.bigocalc.com/
    // Sliding Window (to set one word to be reversed at a time) + Two Pointers (to reverse each word in place).
    string reverseWords(string s) {

        int lPtr = 0; // Defining initial sliding window lPtr

        // Iterates to difine a sliding window: One Word
        for (int rPtr = 0; rPtr < s.length(); ++rPtr) {
            // Defining sliding window rPtr
            if ((s[rPtr] == ' ') || (rPtr == s.length() - 1)) {
                // Two pointers technique inside a sliding window (fixed at this point, but globally dinamic)
                int tmpL = lPtr;
                int tmpR = (rPtr == s.length() - 1) ? rPtr : rPtr - 1;

                // Reversing one word in place
                while (tmpL < tmpR) {
                    // Swapping manually
                    char tmpLChar = s[tmpL];
                    s[tmpL] = s[tmpR]; 
                    s[tmpR] = tmpLChar;
                    // Swapping directly: std::swap(s[tmpL], s[tmpR]); (#include <utility>, or #include <algorithm> older C++ versions)
                    
                    ++tmpL;
                    --tmpR;
                }

                lPtr = rPtr + 1; // Resizing sliding window lPtr for next Word
            }
        }

        return s;

    }
};
