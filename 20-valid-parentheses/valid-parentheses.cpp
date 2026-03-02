class Solution {
public:
    bool isValid (string s) {
        unordered_map<char, char> p_map = {{'(',')'}, {'{','}'}, {'[',']'}}; // Hash map to match parentheses

        stack<char> open_p_stack; // Stack with opening parentheses (keys) LIFO

        // Time complexity O(n) and Space complexity O(n)
        for (int i = 0; i < s.length(); ++i) {
            // If it is an opening parentheses, push to stack -> Procedure
            if (p_map.contains(s[i])) {
                open_p_stack.push(s[i]);
            // If it is a closing parentheses, and it matches with top of stack (opening) pop from stack -> Still Valid
            } else if ((!open_p_stack.empty()) && (s[i] == p_map[open_p_stack.top()])) {
                open_p_stack.pop();
            // If they do not match, s is Not Valid
            } else {
                return false;
            }
        }

        return open_p_stack.empty();

    }
};
