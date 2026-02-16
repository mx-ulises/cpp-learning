class Solution {
private:
    int getOrSum(vector<int>& nums) {
        int orSum = 0;
        for (int num : nums) {
            orSum |= num;
        }
        return orSum;
    }

    int getSubsetsWithOrSum(vector<int>& nums, int target, int current, int i) {
        if (nums.size() == i) {
            return target == current ? 1 : 0;
        }
        int num = nums[i++];
        return getSubsetsWithOrSum(nums, target, current | num, i) + getSubsetsWithOrSum(nums, target, current, i);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maximumOrSum = getOrSum(nums);
        return getSubsetsWithOrSum(nums, maximumOrSum, 0, 0);
    }
};
