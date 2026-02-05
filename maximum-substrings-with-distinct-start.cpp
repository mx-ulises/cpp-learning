class Solution {
private:
    void fillCharPresent(bool * charPresent, const string & s) {
        for (char c: s) {
            charPresent[c - 'a'] = true;
        }
    }

    int getCharPresentCount(const bool * charPresent) {
        int distincts = 0;
        for (int i = 0; i < 26; i++) {
            distincts += charPresent[i] ? 1 : 0;
        }
        return distincts;
    }

public:
    int maxDistinct(string s) {
        bool charPresent[26];
        fillCharPresent(charPresent, s);
        return getCharPresentCount(charPresent);
    }
};
