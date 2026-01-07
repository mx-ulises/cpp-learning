class Solution {
public:
    int mirrorDistance(int n) {
        int m = reverseDigits(n);
        return std::abs(n - m);
    }

    int reverseDigits(int n) {
        int m = 0;
        while (0 < n) {
            m = (10 * m) + (n % 10);
            n /= 10;
        }
        return m;
    }
};
