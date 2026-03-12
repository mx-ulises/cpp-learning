class Solution {
private:
    bool flipIfBar(bool shouldCount, char c) {
        if (c == '|') return shouldCount ^ true;
        return shouldCount;
    }

    int increaseIfShouldCount(bool shouldCount, char c, int asterisks) {
        if (shouldCount && c == '*') asterisks++;
        return asterisks;
    }

public:
    int countAsterisks(string s) {
        int asterisks = 0;
        bool shouldCount = true;
        for (auto c : s) {
            shouldCount = flipIfBar(shouldCount, c);
            asterisks = increaseIfShouldCount(shouldCount, c, asterisks);
        }
        return asterisks;
    }
};
