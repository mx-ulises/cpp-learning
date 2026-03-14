class Solution {
private:
    bool isPalindromic(string& word) {
        for(int i = 0; i < (word.size() / 2); i++) {
            int j = word.size() - i - 1;
            if (word[i] != word[j]) return false;
        }
        return true;
    }

public:
    string firstPalindrome(vector<string>& words) {
        for(auto word : words) {
            if (isPalindromic(word)) return word;
        }
        return "";
    }
};
