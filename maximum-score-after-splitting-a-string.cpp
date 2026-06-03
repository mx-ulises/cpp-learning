class Solution {
private:
    int countOnes(string& s) {
        int ones = 0;
        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }
        return ones;
    }

public:
    int maxScore(string s) {
        int ones = countOnes(s);
        int zeros = 0;
        int maximal = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == '0') {
                zeros++;
            } else {
                ones--;
            }
            maximal = max(maximal, zeros + ones);
        }
        return maximal;
    }
};
