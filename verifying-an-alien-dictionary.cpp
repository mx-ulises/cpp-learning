class Solution {
private:
    int getCharIndex(char c) {
        return c - 'a';
    }

    void fillCharToIndex(vector<int>& charToIndex, string& order) {
        for (int i = 0; i < 26; i++) {
            charToIndex[getCharIndex(order[i])] = i;
        }
    }

    int compareChar(char c1, char c2, vector<int>& charToIndex) {
        return charToIndex[getCharIndex(c1)] - charToIndex[getCharIndex(c2)];
    }

    int compareString(string& word1, string& word2, vector<int>& charToIndex) {
        int l = min(word1.size(), word2.size());
        for (int i = 0; i < l; i++) {
            int comp = compareChar(word1[i], word2[i], charToIndex);
            if (comp != 0) return comp;
        }
        return word1.size() - word2.size();
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        string prev = "";
        vector<int> charToIndex(26);
        fillCharToIndex(charToIndex, order);
        for (string& word : words) {
            if (0 < compareString(prev, word, charToIndex)) {
                return false;
            }
            prev = word;
        }
        return true;
    }
};
