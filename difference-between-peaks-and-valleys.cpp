class Solution {
private:
    int isPeak(vector<int>& nums, int i) {
        return nums[i - 1] < nums[i] && nums[i + 1] < nums[i];
    }

    int addPeakValueIfValid(vector<int>& nums, int i) {
        if (isPeak(nums, i)) return nums[i];
        return 0;
    }

    int isValley(vector<int>& nums, int i) {
        return nums[i - 1] > nums[i] && nums[i + 1] > nums[i];
    }

    int addValleyValueIfValid(vector<int>& nums, int i) {
        if (isValley(nums, i)) return nums[i];
        return 0;
    }

public:
    int peakValleyDifference(vector<int>& nums) {
        int diff = 0;
        for (int i = 1; i < (nums.size() - 1); i++) {
            diff += addPeakValueIfValid(nums, i);
            diff -= addValleyValueIfValid(nums, i);
        }
        return diff;
    }
};
