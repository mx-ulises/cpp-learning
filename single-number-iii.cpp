class Solution {
private:
    int getDiff(vector<int>& nums) {
        long x = 0;
        for (int num : nums) {
            x ^= num;
        }
        return x & -x;
    }

public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> singleNumbers({0, 0});
        int diff = getDiff(nums);
        for (int num : nums) {
            if (diff & num) {
                singleNumbers[0] ^= num;
            } else {
                singleNumbers[1] ^= num;
            }
        }
        return singleNumbers;
    }
};
