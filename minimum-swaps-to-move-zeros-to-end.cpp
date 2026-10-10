class Solution {
private:
    int countZeros(vector<int>& nums) {
        int zeros = 0;
        for (int num : nums) {
            if (num == 0) zeros++;
        }
        return zeros;
    }

public:
    int minimumSwaps(vector<int>& nums) {
        int nonZeros = nums.size() - countZeros(nums);
        int swaps = 0;
        for (int i = 0; i < nonZeros; i++) {
            if (nums[i] == 0) swaps++;
        }
        return swaps;
    }
};
