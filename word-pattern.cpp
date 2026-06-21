class Solution {
private:
    void getWords(string& s, vector<string>& words) {
        s += ' ';
        string currentWord = "";
        for (auto c : s) {
            if (c != ' ') {
                currentWord += c;
            } else {
                words.push_back(currentWord);
                currentWord = "";
            }
        }
    }

public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        getWords(s, words);
        if (words.size() != pattern.size()) {
            return false;
        }
        unordered_map<char, string> char2Word;
        unordered_map<string, char> word2Char;
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string word = words[i];
            char2Word.insert({c, word});
            word2Char.insert({word, c});
            if (word2Char[word] != c || char2Word[c] != word) {
                return false;
            }
        }
        return true;
    }
};
