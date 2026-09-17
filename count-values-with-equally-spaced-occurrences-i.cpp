class Solution {
private:
    bool isMagicSet(vector<int>& indexes) {
        if (indexes.size() == 3) {
            return (indexes[1] - indexes[0]) == (indexes[2] - indexes[1]);
        }
        return false;
    }

public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<vector<int>> numIndexes(101);
        for (int i = 0; i < nums.size(); i++) {
            numIndexes[nums[i]].push_back(i);
        }
        int count = 0;
        for (int i = 1; i < numIndexes.size(); i++) {
            if (isMagicSet(numIndexes[i])) {
                count++;
            }
        }
        return count;
    }
};
