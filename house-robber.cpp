class Solution {
public:
    int rob(vector<int>& nums) {
        int prev0 = 0;
        int prev1 = 0;
        int prev2 = 0;
        int maximal = 0;
        int candidate = -1;
        for (int num : nums) {
            candidate = max(num + prev0, num + prev1);
            maximal = max(maximal, candidate);
            prev0 = prev1;
            prev1 = prev2;
            prev2 = candidate;
        }
        return maximal;
    }
};
