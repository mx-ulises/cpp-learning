struct LastNumIndexes {
    int lastOne;
    int lastTwo;
};

class Solution {
private:
    int getDiff(LastNumIndexes lastNumIndexes) {
        if (lastNumIndexes.lastOne == -1 || lastNumIndexes.lastTwo == -1) return 200;
        return abs(lastNumIndexes.lastOne - lastNumIndexes.lastTwo);
    }

    LastNumIndexes updateLastNumIndexes(LastNumIndexes lastNumIndexes, int num, int i) {
        if (num == 1) lastNumIndexes.lastOne = i;
        if (num == 2) lastNumIndexes.lastTwo = i;
        return lastNumIndexes;
    }

public:
    int minAbsoluteDifference(vector<int>& nums) {
        LastNumIndexes lastNumIndexes = {-1, -1};
        int diff = 200;
        for (int i = 0; i < nums.size(); i++) {
            lastNumIndexes = updateLastNumIndexes(lastNumIndexes, nums[i], i);
            diff = min(diff, getDiff(lastNumIndexes));
        }
        if (diff == 200) diff = -1;
        return diff;
    }
};
