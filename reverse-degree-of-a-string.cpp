class Solution {
public:
    int reverseDegree(string s) {
        int degree = 0;
        for (int i = 0; i < s.size(); i++) {
            degree += charReverseDegree(s[i]) * (i + 1);
        }
        return degree;
    }

    int charReverseDegree(char c) {
        return 26 - c + 'a';
    }
};
