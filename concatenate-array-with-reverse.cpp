class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int i = nums.size() - 1;
        while (0 <= i) {
            nums.push_back(nums[i]);
            i--;
        }
        return nums;
    }
};
