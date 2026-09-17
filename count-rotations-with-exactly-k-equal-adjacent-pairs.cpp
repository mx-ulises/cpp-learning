class Solution {
private:
    int getMaxScore(string& s) {
        int maxScore = 0;
        char prev = s[s.size() - 1];
        for (char current : s) {
            if (prev == current) maxScore++;
            prev = current;
        }
        return maxScore;
    }

    int getRotationsWithScore(int maxScore, int k, int n) {
        if (maxScore == k) return n - maxScore;
        if ((maxScore - 1) == k) return maxScore;
        return 0;
    }

public:
    int countRotations(string s, int k) {
        int maxScore = getMaxScore(s);
        return getRotationsWithScore(maxScore, k, s.size());
    }
};
