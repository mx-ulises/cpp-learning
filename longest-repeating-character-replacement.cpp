class Solution {
private:
    int findSubstringWithReplacement(string& s, int k, int c) {
        int left = 0, right = 0, maximal = 0;
        while (right < s.size()) {
            if (s[right] != c) k--;
            right++;
            while (k < 0) {
                if (s[left] != c) k++;
                left++;
            }
            maximal = max(maximal, right - left);
        }
        return maximal;
    }

public:
    int characterReplacement(string s, int k) {
        int maximal = 0;
        for (char c = 'A'; c <= 'Z'; c++) {
            maximal = max(maximal, findSubstringWithReplacement(s, k, c));
        }
        return maximal;
    }
};
