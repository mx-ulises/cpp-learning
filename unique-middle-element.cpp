class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums[nums.size() / 2];
        int midCount = 0;
        for (int num : nums) {
            if (num == mid) midCount++;
        }
        return midCount == 1;
    }
};
