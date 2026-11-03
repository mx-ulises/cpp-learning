class Solution {
private:
    int getNumSum(vector<int>& nums) {
        int numSum = 0;
        for (int num : nums) {
            numSum += num;
        }
        return numSum;
    }

    bool isDominant(int numExpanded, int numSum) {
        return numSum < numExpanded;
    }

public:
    int dominantIndices(vector<int>& nums) {
        int dominantCount = 0;
        int numSum = getNumSum(nums);
        for (int i = 0; i < nums.size() - 1; i++) {
            numSum -= nums[i];
            int count = nums.size() - i - 1;
            if (isDominant(nums[i] * count, numSum)) {
                dominantCount++;
            }
        }
        return dominantCount;
    }
};
