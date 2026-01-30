class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = getSum(nums);
        return sum % k;
    }

    int getSum(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        return sum;
    }
};
