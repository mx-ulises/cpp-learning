class Solution {
private:
    void updateCurrentBalanceAndSubstringCount(char c, int& currentBalance, int& balanceSubstringCount) {
        currentBalance += (c == 'R')? 1 : -1;
        balanceSubstringCount += currentBalance? 0 : 1;
    }

public:
    int balancedStringSplit(string s) {
        int balanceSubstringCount = 0;
        int currentBalance = 0;
        for (char c : s) {
            updateCurrentBalanceAndSubstringCount(c, currentBalance, balanceSubstringCount);
        }
        return balanceSubstringCount;
    }
};
