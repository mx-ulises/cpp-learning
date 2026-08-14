class Solution {
private:
    int getMaxProduct(vector<int>& nums, int start, int end, int dir) {
        int maximal = nums[start];
        int current = 1;
        for (int i = start; i != end; i += dir) {
            current *= nums[i];
            maximal = max(maximal, current);
            if (current == 0) current = 1;
        }
        return maximal;
    }

public:
    int maxProduct(vector<int>& nums) {
        int leftToRight = getMaxProduct(nums, 0, nums.size(), 1);
        int rightToLeft = getMaxProduct(nums, nums.size() - 1, -1, -1);
        return max(leftToRight, rightToLeft);
    }
};
