class Solution {
private:
    void fillNumSet(vector<int>& nums, unordered_set<int>& numSet) {
        for (auto num : nums) {
            numSet.insert(num);
        }
    }

    int checkConsecutives(unordered_set<int>& numSet, int num) {
        int consecutives = 0;
        while (numSet.count(num)) {
            num++;
            consecutives++;
        }
        return consecutives;
    }

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        fillNumSet(nums, numSet);
        int maximal = 0;
        for (auto num : numSet) {
            if (!numSet.count(num - 1)) {
                maximal = max(maximal, checkConsecutives(numSet, num));
            }
        }
        return maximal;
    }
};
