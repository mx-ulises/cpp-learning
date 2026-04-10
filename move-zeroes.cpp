class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZeroCount] = nums[i];
                nonZeroCount++;
            }
        }
        for (int i = nonZeroCount; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
