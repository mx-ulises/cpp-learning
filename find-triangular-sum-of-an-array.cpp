class Solution {
private:
    int adjustNum(int x) {
        if (10 <= x) {
            return x - 10;
        }
        return x;
    }

    void updateArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            int j = i - 1;
            nums[j] = adjustNum(nums[i] + nums[j]);
        }
        nums.pop_back();
    }

public:
    int triangularSum(vector<int>& nums) {
        while (1 < nums.size()) {
            updateArray(nums);
        }
        return nums[0];        
    }
};
