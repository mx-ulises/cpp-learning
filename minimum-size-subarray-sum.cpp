class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long currentSum = 0;
        int left = 0, right = 0;
        int minLen = nums.size() + 1;
        while (right < nums.size()) {
            currentSum += nums[right];
            right++;
            while (target <= currentSum) {
                minLen = min(minLen, right - left);
                currentSum -= nums[left];
                left++;
            }
        }
        return minLen % (nums.size() + 1);
    }
};
