class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minimal = nums[0];
        int currentSum = 0;
        for (int num : nums) {
            currentSum += num;
            minimal = min(minimal, currentSum);
        }
        return max(1, 1 - minimal);
    }
};
