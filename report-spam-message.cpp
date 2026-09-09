class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> banned;
        for (string& word : bannedWords) {
            banned.insert(word);
        }
        int spamWords = 0;
        for (string& word : message) {
            if (banned.count(word)) spamWords++;
            if (1 < spamWords) return true;
        }
        return false;
    }
};
