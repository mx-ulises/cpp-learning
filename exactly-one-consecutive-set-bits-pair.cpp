class Solution {
private:
    bool matchMask(int mask, int n) {
        return (mask & n) == mask;
    }

public:
    bool consecutiveSetBits(int n) {
        int mask = 3;
        int consecutiveCount = 0;
        while (mask <= n) {
            if (matchMask(mask, n)) consecutiveCount++;
            mask <<= 1;
        }
        return consecutiveCount == 1;
    }
};
