class Solution {
public:
    const std::vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

    string sortVowels(string s) {
        vector<int> vowelCount = getVowelCount(s);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(std::find(vowels.begin(), vowels.end(), c) != vowels.end()) {
                int charIndex = getCurrentCharIndex(vowelCount);
                vowelCount[charIndex]--;
                s[i] = vowels[charIndex];
            }
        }
        return s;
    }

    std::vector<int> getVowelCount(string s) {
        std::vector<int> vowelCount(10, 0);
        for (int i = 0; i < s.size(); i++) {
            int charIndex = getCharIndex(s[i]);
            if (charIndex != -1) {
                vowelCount[charIndex]++;
            }
        }
        return vowelCount;
    }

    int getCurrentCharIndex(std::vector<int> vowelCount) {
        for (int i = 0; i < vowelCount.size(); i++) {
            if (0 < vowelCount[i]) {
                return i;
            }
        }
        return -1;
    }

    int getCharIndex(char c) {
        auto it = std::find(vowels.begin(), vowels.end(), c);
        if (it == vowels.end()) {
            return -1; // not found
        }
        return static_cast<int>(std::distance(vowels.begin(), it));    }
};
