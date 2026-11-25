class Solution {
private:
    bool isOdd(int x) {
        return (x & 1) == 1;
    }

public:
    int countOdds(int low, int high) {
        int total = (high - low) / 2;
        if (isOdd(low) || isOdd(high)) total++;
        return total;
    }
};
