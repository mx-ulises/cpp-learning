class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right]) return nums[left];
            int mid = (left + right) / 2;
            int prev = (mid - 1) % nums.size();
            if (nums[mid] < nums[prev]) return nums[mid];
            else if (nums[right] < nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return nums[left];
    }
};
