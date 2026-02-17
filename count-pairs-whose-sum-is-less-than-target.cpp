class Solution {
private:
    int getNumCountLessThanTarget(vector<int>& nums, int start, int target) {
        int count = 0;
        for (int i = start; i < nums.size(); i++) {
            count += nums[i] < target ? 1 : 0;
        }
        return count;
    }

public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += getNumCountLessThanTarget(nums, i + 1, target - nums[i]);
        }
        return count;
    }
};
