class Solution {
private:
    int getDirection(int n, int k) {
        int reverses = k / n;
        if (reverses & 1) return -1;
        return 1;
    }

    int getOffset(int n, int k) {
        return k % n;
    }

public:
    int numberOfChild(int n, int k) {
        n--;
        int direction = getDirection(n, k);
        int offset = getOffset(n, k);
        if (direction < 0) return n - offset;
        return offset;
    }
};
