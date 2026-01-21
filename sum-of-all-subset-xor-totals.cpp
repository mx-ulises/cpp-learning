class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return subsetXORSum(nums, 0, 0);
    }

    int subsetXORSum(vector<int>& nums, int i, int current) {
        if (nums.size() - 1 == i) {
            return current + (current ^ nums[i]);
        }
        i++;
        return subsetXORSum(nums, i, current) + subsetXORSum(nums, i, current ^ nums[i - 1]);
    }
};
