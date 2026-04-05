class Solution {
private:
    int updateCurrent(int currentCount, int current, int num) {
        if (currentCount == 0) return num;
        return current;
    }

    int updateCurrentCount(int currentCount, int current, int num) {
        if (current == num) return currentCount + 1;
        return currentCount - 1;
    }

public:
    int majorityElement(vector<int>& nums) {
        int current;
        int currentCount = 0;
        for (int num : nums) {
            current = updateCurrent(currentCount, current, num);
            currentCount = updateCurrentCount(currentCount, current, num);
        }
        return current;
    }
};
