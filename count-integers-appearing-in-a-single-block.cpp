class Solution {
private:
    void fillSpecialIntegers(vector<int>& nums, unordered_map<int, bool>& isSpecial) {
        isSpecial[nums[0]] = true;
        int prev = nums[0];
        int current = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            current = nums[i];
            if (isSpecial.count(current) == 0) {
                isSpecial[current] = true;
            } else if (prev != current) {
                isSpecial[current] = false;
            }
            prev = current;
        }
    }

public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, bool> isSpecial;
        fillSpecialIntegers(nums, isSpecial);
        int specialIntegers = 0;
        for (const auto& [num, special] : isSpecial) {
            if (special) specialIntegers++;
        }
        return specialIntegers;
    }
};
