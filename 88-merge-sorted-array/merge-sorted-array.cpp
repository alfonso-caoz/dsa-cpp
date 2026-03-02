class Solution {
public: 
    // Time Complexity O(m+n). Space Complexity O(1).
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i_m = m - 1;
        int i_n = n - 1;
        int i_mn = m + n - 1;

        while (i_n >= 0) {
            if (i_m >= 0 && nums1[i_m] > nums2[i_n]) {
                nums1[i_mn--] = nums1[i_m--]; // First, it access to nums1[i_mn] and then (i_mn - 1), next iteration nums1[(i_mn - 1)]
            } else {
                nums1[i_mn--] = nums2[i_n--]; // First, it access to nums1[i_mn] and then (i_mn - 1), next iteration nums1[(i_mn - 1)]
            }
        }

    }
};
