class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastWordLen = 0;
        int currentLen = 0;
        for (char c : s) {
            if (c == ' ' && 0 < currentLen) {
                lastWordLen = currentLen;
                currentLen = 0;
            } else if (c != ' ') {
                currentLen++;
                lastWordLen = currentLen;
            }
        }
        return lastWordLen;
    }
};
