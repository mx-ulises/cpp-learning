class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid = -1;
        while (left < right) {
            mid = (left + right) / 2;
            if ((mid & 1) == 1 && nums[mid - 1] == nums[mid]) left = mid + 1;
            else if ((mid & 1) == 0 && nums[mid + 1] == nums[mid]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};
