class Solution {
public:
    int countValidPrefixes(string s) {
        unordered_map<char,int> charCount;
        int preffixCount = 0;
        for (char c : s) {
            charCount[c]++;
            if (abs(charCount['0'] - charCount['1']) <= 1) {
                preffixCount++;
            }
        }
        return preffixCount;
    }
};
