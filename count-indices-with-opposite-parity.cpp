class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> output(nums.size());
        vector<int> parityCount({0, 0});
        for (int i = nums.size() - 1; 0 <= i; i--) {
            int parity = nums[i] & 1;
            output[i] = parityCount[parity ^ 1];
            parityCount[parity]++;
        }
        return output;
    }
};
