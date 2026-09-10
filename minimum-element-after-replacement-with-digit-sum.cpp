class Solution {
private:
    int digitSum(int num) {
        int sum = 0;
        while (0 < num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minElement(vector<int>& nums) {
        int minimal = 100000;
        for (int num : nums) {
            minimal = min(minimal, digitSum(num));
        }
        return minimal;
    }
};
