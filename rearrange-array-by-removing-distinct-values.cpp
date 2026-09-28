class Solution {
private:
    void fillNumCount(vector<int>& nums, vector<int>& numCount) {
        for (int num : nums) {
            numCount[num]++;
        }
    }

    int passAndUpdateIndex(vector<int>& numCount, vector<int>& ans, int i) {
        for (int j = 1; j <= 100; j++) {
            if (0 < numCount[j]) {
                ans[i] = j;
                numCount[j]--;
                i++;
            }
        }
        return i;
    }

public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> numCount(101);
        fillNumCount(nums, numCount);
        vector<int> ans(nums.size());
        int i = 0;
        while (i < nums.size()) {
            i = passAndUpdateIndex(numCount, ans, i);
        }
        return ans;
    }
};
