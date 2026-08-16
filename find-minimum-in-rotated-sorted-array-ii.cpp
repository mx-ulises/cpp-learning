class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimal = nums[0];
        for (int num : nums) {
            minimal = min(minimal, num);
        }
        return minimal;
    }
};
