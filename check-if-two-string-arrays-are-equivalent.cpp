class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int word1_index = 0;
        int word2_index = 0;
        int word1_char_index = 0;
        int word2_char_index = 0;
        while (word1_index < word1.size() && word2_index < word2.size()) {
            if (word1[word1_index][word1_char_index] != word2[word2_index][word2_char_index]) {
                return false;
            }
            word1_char_index = updateCharIndex(word1[word1_index].size(), word1_char_index);
            word2_char_index = updateCharIndex(word2[word2_index].size(), word2_char_index);
            word1_index = updateWordIndex(word1_char_index, word1_index);
            word2_index = updateWordIndex(word2_char_index, word2_index);
        }
        return word1_index == word1.size() && word2_index == word2.size();
    }

    int updateCharIndex(int word_size, int char_index) {
        return ++char_index == word_size? 0 : char_index;
    }

    int updateWordIndex(int char_index, int word_index) {
        return !char_index? ++word_index: word_index;
    }
};
