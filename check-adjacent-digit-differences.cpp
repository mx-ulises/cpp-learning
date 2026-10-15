class Solution {
private:
    int getDigitInt(int c) {
        return c - '0';
    }

    int getDiff(int a, int b) {
        return abs(a - b);
    }

public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int prev = getDigitInt(s[0]);
        for (int i = 1; i < s.size(); i++) {
            int current = getDigitInt(s[i]);
            if (2 < getDiff(prev, current)) {
                return false;
            }
            prev = current;
        }
        return true;
    }
};
