class Solution {
public:
    int digitFrequencyScore(int n) {
        int frequencyScore = 0;
        while (0 < n) {
            frequencyScore += n % 10;
            n /= 10;
        }
        return frequencyScore;
    }
};
