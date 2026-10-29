class Solution {
public:
    string trimTrailingVowels(string s) {
        int prefixSize = s.size();
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        while (0 < prefixSize && vowels.count(s[prefixSize - 1])) {
            prefixSize--;
        }
        return s.substr(0, prefixSize);
    }
};
