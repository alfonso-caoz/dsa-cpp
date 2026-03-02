class Solution {
public:
    // Time Complexity O(n). Space Complexity O(1).
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;

        int count = 0;
        
        for (int i = 0; i < flowerbed.size(); ++i) {
            bool leftEmpty  = i == 0 || flowerbed[i - 1] == 0;
            bool rightEmpty = i == flowerbed.size() - 1 || flowerbed[i + 1] == 0;

            if (leftEmpty && flowerbed[i] == 0 && rightEmpty) {
                ++count;
                if (count == n) return true;
                ++i;
            }

        }

        return false;

    }
};
