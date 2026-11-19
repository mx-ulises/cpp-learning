class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int perimeter = 0;
        for (int i = nums.size() - 1; 2 <= i; i--) {
            if (nums[i] < (nums[i - 1] + nums[i - 2])) {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }
};
