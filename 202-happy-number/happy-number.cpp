class Solution {
public:
    // Floyd´s cycle finding algorithm or Hare and Tortoise Algorithm
    // Time complexity O(logn) [???]. Space complexity O(1).
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        // At least one execution, because slow = fast = n already, not just while loop.
        do {
            if (fast == 1) return true;
            slow = sumSquare(slow);
            fast = sumSquare(sumSquare(fast));
        } while (slow != fast);

        return slow == 1;

    }

private:
    // It calculates the sum of the squares of the digits of a number.
    int sumSquare(int n) {
        int ans = 0;

        while (n > 0) {
            int digit = n % 10;
            ans += digit * digit;
            n /= 10;
        }

        return ans;

    }

};
