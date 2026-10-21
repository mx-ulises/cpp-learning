class Solution {
private:
    bool hasDigit(int n, int x) {
        if (n == x) return true;
        while (0 < n) {
            int digit = n % 10;
            if (digit == x) return true;
            n /= 10;
        }
        return false;
    }

    int firstDigit(int n) {
        while (10 <= n) {
            n /= 10;
        }
        return n;
    }

public:
    bool validDigit(int n, int x) {
        return hasDigit(n, x) && firstDigit(n) != x;
    }
};
