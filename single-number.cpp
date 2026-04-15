class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (auto num: nums) {
            xorSum ^= num;
        }
        return xorSum;
    }
};
