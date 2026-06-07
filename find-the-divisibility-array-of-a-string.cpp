class Solution {
private:
    unsigned long toDigit(char c) {
        return c - '0';
    }

    unsigned long updatePrefix(unsigned long prefix, unsigned long digit, unsigned long m) {
        return (prefix * 10 + digit) % m;
    }

public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> output(word.size());
        unsigned long prefix = 0;
        for (int i = 0; i < word.size(); i++) {
            prefix = updatePrefix(prefix, toDigit(word[i]), m);
            if (prefix == 0) {
                output[i] = 1;
            }
        }
        return output;
    }
};
