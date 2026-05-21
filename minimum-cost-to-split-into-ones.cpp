class Solution {
public:
    int minCost(int x) {
        if (x <= 1) return 0;
        int a = x / 2;
        int b = x - a;
        return minCost(a) + minCost(b) + a * b;
    }
};
