class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> numToAns(1001);
        for (int i = 0; i < 1001; i++) {
            numToAns[i] = -1;
        }
        for (int i = 0; i < 1001; i++) {
            int num = i | (i + 1);
            if (num < 1001 && numToAns[num] == -1) numToAns[num] = i;
        }
        vector<int> ans(nums.size());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = numToAns[nums[i]];
        }
        return ans;
    }
};
