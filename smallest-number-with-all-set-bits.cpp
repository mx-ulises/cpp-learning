class Solution {
private:
    int getBitLen(int n) {
        int bitLen = 0;
        while (0 < n) {
            n >>= 1;
            bitLen++;
        }
        return bitLen;
    }
public:
    int smallestNumber(int n) {
        int shift = getBitLen(n);
        return (1 << shift) - 1;
    }
};
