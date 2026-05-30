class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string translateToGoat(string& word, const string& maSuffix) {
        if (isVowel(word[0]) == false) {
            char c = word[0];
            word.erase(0, 1);
            word += c;
        }
        return word + maSuffix;
    }

    void addWord(string& goatLatinSentence, string& currentWord, const string& maSuffix) {
        if (goatLatinSentence.size() != 0) {
            goatLatinSentence += " ";
        }
        goatLatinSentence += translateToGoat(currentWord, maSuffix);
    }

public:
    string toGoatLatin(string sentence) {
        string goatLatinSentence = "";
        string currentWord = "";
        string maSuffix = "maa";
        for (char c : sentence) {
            if (c == ' ') {
                addWord(goatLatinSentence, currentWord, maSuffix);
                maSuffix += 'a';
                currentWord = "";
            } else {
                currentWord += c;
            }
        }
        addWord(goatLatinSentence, currentWord, maSuffix);
        return goatLatinSentence;
    }
};
