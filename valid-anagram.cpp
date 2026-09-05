class Solution {
private:
    void addCounts(vector<int>& charCount, string& s, int counter) {
        for (char c : s) {
            charCount[c - 'a'] += counter;
        }
    }

    bool testCharCount(vector<int>& charCount) {
        for (int i = 0; i < 26; i++) {
            if (charCount[i] != 0) return false;
        }
        return true;
    }

public:
    bool isAnagram(string s, string t) {
        vector<int> charCount(26);
        addCounts(charCount, s, 1);
        addCounts(charCount, t, -1);
        return testCharCount(charCount);
    }
};
