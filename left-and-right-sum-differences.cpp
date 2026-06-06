class Solution {
private:
    int getTotalSum(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        return totalSum;
    }

public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rightSum = getTotalSum(nums);
        int leftSum = 0;
        vector<int> leftRightSumDiff(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];
            leftRightSumDiff[i] = abs(rightSum - leftSum);
            leftSum += nums[i];
        }
        return leftRightSumDiff;
    }
};
