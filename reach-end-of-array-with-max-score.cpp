class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long currnetMaximal = nums[0];
        long long i = 0;
        long long maximalScore = 0;
        for (long long j = 1; j < nums.size(); j++) {
            if (currnetMaximal < nums[j]) {
                maximalScore += (j - i) * currnetMaximal;
                currnetMaximal = nums[j];
                i = j;
            }
        }
        maximalScore += (nums.size() - i - 1) * currnetMaximal;
        return maximalScore;
    }
};
