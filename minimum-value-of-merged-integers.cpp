class Solution {
private:
    int getDigits(int a) {
        int digits = 1;
        while (digits <= a) {
            digits *= 10;
        }
        return digits;
    }

    int merge(int a, int b) {
        return a * getDigits(b) + b;
    }

public:
    int minMergedInteger(vector<int>& nums) {
        int minimal = 10001000;
        for (int i = 0; i < nums.size(); i += 2) {
            int merged = merge(nums[i], nums[i + 1]);
            minimal = min(minimal, merged);
        }
        return minimal;
    }
};
