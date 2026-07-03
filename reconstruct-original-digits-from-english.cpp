class Solution {
private:
    unordered_map<char,int> getCharCount(string& s) {
        unordered_map<char,int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        return charCount;
    }

    int getDigitCountAndRemoveChars(unordered_map<char,int>& charCount, char c, string num) {
        int count = charCount[c];
        for (char c : num) {
            charCount[c] -= count;
        }
        return count;
    }

    unordered_map<char,int> getDigitCount(unordered_map<char,int>& charCount) {
        unordered_map<char,int> digitCount;
        digitCount['0'] = getDigitCountAndRemoveChars(charCount, 'z', "zero");
        digitCount['2'] = getDigitCountAndRemoveChars(charCount, 'w', "two");
        digitCount['4'] = getDigitCountAndRemoveChars(charCount, 'u', "four");
        digitCount['6'] = getDigitCountAndRemoveChars(charCount, 'x', "six");
        digitCount['8'] = getDigitCountAndRemoveChars(charCount, 'g', "eight");
        digitCount['1'] = getDigitCountAndRemoveChars(charCount, 'o', "one");
        digitCount['3'] = getDigitCountAndRemoveChars(charCount, 't', "three");
        digitCount['5'] = getDigitCountAndRemoveChars(charCount, 'f', "five");
        digitCount['7'] = getDigitCountAndRemoveChars(charCount, 's', "seven");
        digitCount['9'] = getDigitCountAndRemoveChars(charCount, 'i', "nine");
        return digitCount;
    }

    string getOutput(unordered_map<char,int>& digitCount) {
        string output = "";
        for (char d = '0'; d <= '9'; d++) {
            output += string(digitCount[d], d);
        }
        return output;
    }

public:
    string originalDigits(string s) {
        unordered_map<char,int> charCount = getCharCount(s);
        unordered_map<char,int> digitCount = getDigitCount(charCount);
        return getOutput(digitCount);
    }
};
