enum CharType {
    Vowel,
    Consonant
};

class Solution {
private:
    const unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};

    bool isVowel(char c) {
        return VOWELS.count(c);
    }

    bool isChar(char c) {
        return 'a' <= c && c <= 'z';
    }

    bool isConsonant(char c) {
        return isChar(c) && !isVowel(c);
    }

    bool isCharOfType(char c,  CharType charType) {
        if (charType == Vowel) return isVowel(c);
        if (charType == Consonant) return isConsonant(c);
        return false;
    }

    int countCharType(string s, CharType charType) {
        int count = 0;
        for (char c : s) {
            if (isCharOfType(c, charType)) {
                count++;
            }
        }
        return count;
    }

public:
    int vowelConsonantScore(string s) {
        int v = countCharType(s, Vowel);
        int c = countCharType(s, Consonant);
        if (c > 0) return v / c;
        return 0;
    }
};
