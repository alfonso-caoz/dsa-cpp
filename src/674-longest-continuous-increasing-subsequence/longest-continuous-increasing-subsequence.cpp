class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
       
        int LCIS_counter = 1;
        int LCIS_sub_counter = 1;
        if (nums.size() == 1) return LCIS_counter;
        
        for (size_t i = 0; i < nums.size()-1; ++i) {
            if (nums[i] < nums[i+1]) {
                ++LCIS_counter;
            } else {
                if (LCIS_sub_counter < LCIS_counter) {
                    LCIS_sub_counter = LCIS_counter;
                }
                LCIS_counter = 1;
            }
        }

        return (LCIS_sub_counter < LCIS_counter) ? LCIS_counter : LCIS_sub_counter;

    }
};
