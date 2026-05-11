class Solution {
private:
    int getSquareIfSpecial(int num, int n, int i) {
        if (n % i == 0) {
            return num * num;
        }
        return 0;
    }

public:
    int sumOfSquares(vector<int>& nums) {
        int s = 0;
        for (int i = 1; i <= nums.size(); i++) {
            s += getSquareIfSpecial(nums[i - 1], nums.size(), i);
        }
        return s;
    }
};
