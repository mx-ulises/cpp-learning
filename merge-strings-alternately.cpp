class Solution {
private:
    int addIfValidAndShift(string& merged, int j, const string& word, int i) {
        if (i < word.size()) {
            merged[j] = word[i];
            j++;
        }
        return j;
    }
public:
    string mergeAlternately(string word1, string word2) {
        string merged(word1.size() + word2.size(), ' ');
        int i = 0;
        int j = 0;
        while(j < merged.size()) {
            j = addIfValidAndShift(merged, j, word1, i);
            j = addIfValidAndShift(merged, j, word2, i);
            i++;
        }
        return merged;
    }
};
