class Solution {
public:
    int hammingWeight(int n) {
        int bits = 0;
        while (0 < n) {
            bits += n & 1;
            n >>= 1;
        }
        return bits;
    }
};
