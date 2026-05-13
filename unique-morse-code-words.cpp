class Solution {
private:
    const vector<string> alphabet{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    void insertTranslatedWord(string& word, unordered_set<string>& uniqueTranslatedWords) {
        string translated = "";
        for (char c: word) {
            translated += alphabet[c - 'a'];
        }
        uniqueTranslatedWords.insert(translated);
    }

public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> uniqueTranslatedWords;
        for (string word : words) {
            insertTranslatedWord(word, uniqueTranslatedWords);
        }
        return uniqueTranslatedWords.size();
    }
};
