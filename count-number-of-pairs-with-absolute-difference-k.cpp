class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        std::vector<int> numCount(101);
        int pairCount = 0, num = 0;
        for (int i = 0; i < nums.size(); i++) {
            num = nums[i];
            numCount[num]++;
            pairCount += getValidNumCount(numCount, num + k) + getValidNumCount(numCount, num - k);
        }
        return pairCount;
    }

    int getValidNumCount(vector<int>& numCount, int num) {
        if (1 <= num && num <= 100) {
            return numCount[num];
        }
        return 0;
    }
};
