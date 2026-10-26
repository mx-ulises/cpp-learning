class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int currentGroupValue = -1;
        int currentGroupSize = 0;
        int deletions = 0;
        for (int num: nums) {
            if (currentGroupValue != num) {
                deletions += max(0, currentGroupSize - 1);
                currentGroupSize = 0;
                currentGroupValue = num;
            }
            currentGroupSize++;
        }
        deletions += max(0, currentGroupSize - 1);
        return deletions;
    }
};
