class Solution {
private:
    bool pickFirstVector(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n < 0) {
            return true;
        }
        if (m < 0) {
            return false;
        }
        return nums2[n] < nums1[m];
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m + n - 1;
        m--;
        n--;
        while (0 <= m || 0 <= n) {
            if (pickFirstVector(nums1, m, nums2, n)) {
                nums1[l] = nums1[m];
                m--;
            } else {
                nums1[l] = nums2[n];
                n--;
            }
            l--;
        }
    }
};
