class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> numCount(nums.size());
        for (int num : nums) {
            numCount[num - 1]++;
        }
        vector<int> output(2);
        for (int i = 0; i < numCount.size(); i++) {
            if (numCount[i] == 0) {
                output[1] = i + 1;
            }
            if (numCount[i] == 2) {
                output[0] = i + 1;
            }
        }
        return output;
    }
};
