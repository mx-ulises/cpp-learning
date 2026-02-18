class Solution {
private:
    bool isOdd(int n) {
        return (n & 1) == 1;
    }

public:
    int smallestEvenMultiple(int n) {
        return n << isOdd(n);
    }
};
