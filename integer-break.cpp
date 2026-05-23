class Solution {
private:
    int getMaximalBreak(int n, vector<int>& maximalBreaks) {
        int maximalBreak = 0;
        for(int a = 1; a < n; a++) {
            int b = n - a;
            int maximalA = max(a, maximalBreaks[a]);
            int maximalB = max(b, maximalBreaks[b]);
            maximalBreak = max(maximalBreak, maximalA * maximalB);
        }
        return maximalBreak;
    }

public:
    int integerBreak(int n) {
        vector<int> maximalBreaks(n + 1);
        for (int i = 0; i < maximalBreaks.size(); i++) {
            maximalBreaks[i] = getMaximalBreak(i, maximalBreaks);
        }
        return maximalBreaks[n];
    }
};
