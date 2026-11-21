class Solution {
private:
    int testAndUpdateMinDistance(int num, int target, int minDistance, int distance) {
        if (num == target) {
            minDistance = min(minDistance, distance);
        }
        return minDistance;
    }

public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDistance = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            minDistance = testAndUpdateMinDistance(nums[i], target, minDistance, abs(i - start));
        }
        return minDistance;
    }
};
