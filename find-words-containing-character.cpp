class Solution {
private:
    bool wordContains(string& word, char x) {
        for (char c : word) {
            if (c == x) {
                return true;
            }
        }
        return false;
    }

public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> output(0);
        for (int i = 0; i < words.size(); i++) {
            if (wordContains(words[i], x)) {
                output.push_back(i);
            }
        }
        return output;
    }
};
