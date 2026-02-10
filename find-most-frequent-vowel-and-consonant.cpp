class Solution {
    bool isVowel(char c) {
        switch (c) {
            case 'a': return false;
            case 'e': return false;
            case 'i': return false;
            case 'o': return false;
            case 'u': return false;
        }
        return true;
    }

public:
    int maxFreqSum(string s) {
        int frequencies [26] = {};
        int position = -1;
        int maxVowel = 0;
        int maxConsonant = 0;
        for (char c : s) {
            position = c - 'a';
            frequencies[position]++;
            if (isVowel(c)) {
                maxVowel = max(maxVowel, frequencies[position]);
            } else {
                maxConsonant = max(maxConsonant, frequencies[position]);
            }
        }
        return maxVowel + maxConsonant;
    }
};
