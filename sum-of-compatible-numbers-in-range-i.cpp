class Solution {
private:
    int getCompaitibilyInt(int n, int x) {
        if ((n & x) == 0) return x;
        return 0;
    }

public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0, start = max(n - k, 1), end = n + k;
        for (int x = start; x <= end; x++) {
            sum += getCompaitibilyInt(n, x);
        }
        return sum;
    }
};
