class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        paragraph += ' ';
        string current = "";
        string output = "";
        int mostCommonWordCount = 0;
        unordered_map<string,int> wordCount;
        unordered_set<string> bannedWords(banned.begin(), banned.end());
        bannedWords.insert("");
        for (auto c: paragraph) {
            if (isalpha(c)) {
                current += tolower(c);
            } else {
                if (bannedWords.find(current) == bannedWords.end()) {
                    wordCount[current]++;
                    if (mostCommonWordCount < wordCount[current]) {
                        mostCommonWordCount = wordCount[current];
                        output = current;
                    }
                }
                current = "";
            }
        }
        return output;
    }
};
