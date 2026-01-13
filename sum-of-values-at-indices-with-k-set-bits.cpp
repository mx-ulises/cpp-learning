class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += getIfIndexIsKSetBits(nums[i], i, k);
        }
        return sum;
    }

    int getIfIndexIsKSetBits(int num, int i, int k) {
        return isKSetBits(i, k) ? num : 0;
    }

    bool isKSetBits(int i, int k) {
        return getSetBits(i) == k;
    }

    int getSetBits(int i) {
        int setBits = 0;
        while (0 < i) {
            setBits += i & 1;
            i >>= 1;
        }
        return setBits;
    }

};
