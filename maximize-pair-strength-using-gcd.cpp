class Solution {
private:
    int getGDC(int num1, int num2) {
        if (num2 == 0) {
            return num1;
        }
        return getGDC(num2, num1 % num2);
    }

public:
    long long maxPairStrength(vector<int>& nums) {
        long long maxStrength = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long gdc = getGDC(nums[i], nums[j]);
                long long candidate = (nums[i] / gdc) * (nums[j] / gdc);
                maxStrength = max(maxStrength, candidate);
            }
        }
        return maxStrength;
    }
};
