class Solution {
public:
    int xorOperation(int n, int start) {
        int result = start;
        int current = start;
        for (int i = 1; i < n; i++) {
            current += 2;
            result ^= current;
        }
        return result;
    }
};
