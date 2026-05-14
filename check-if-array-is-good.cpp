class Solution {
private:
    bool isValidEntry(int num, vector<int>& numCount, int n) {
        if (numCount.size() <= num) return false;
        if (0 < numCount[num] && num != n) return false;
        if (1 < numCount[num]) return false;
        return true;
    }

public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> numCount(n + 1);
        for (int num : nums) {
            if (!isValidEntry(num, numCount, n)) return false;
            numCount[num]++;
        }
        return true;
    }
};
