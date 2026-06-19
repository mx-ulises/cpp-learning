class Solution {
public:
    bool hasAlternatingBits(int n) {
        int d = n & 1;
        int prev =d;
        n >>= 1;
        while (0 < n) {
            d = n & 1;
            if (d == prev) return false;
            prev = d;
            n >>= 1;
        }
        return true;
    }
};
