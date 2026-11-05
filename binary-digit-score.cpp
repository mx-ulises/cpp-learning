class Solution {
private:
    int getSetBits(int x) {
        int s = 0;
        while (0 < x) {
            s += x & 1;
            x >>= 1;
        }
        return s;
    }

public:
    int calculateScore(int a, int b) {
        int s1 = getSetBits(a);
        int s2 = getSetBits(b);
        if (s1 >= s2) return s1 * s2;
        return s2 / s1;
    }
};
