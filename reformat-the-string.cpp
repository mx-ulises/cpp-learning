class Solution {
private:
    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }

    void fillDigitOnly(string& s, string& digitOnly) {
        for (char c : s) {
            if (isDigit(c)) digitOnly += c;
        }
    }

    void fillAlphaOnly(string& s, string& alphaOnly) {
        for (char c : s) {
            if (!isDigit(c)) alphaOnly += c;
        }
    }

    void fillOutput(string& first, string& second, string& output) {
        for(int i = 0; i < second.size(); i++) {
            output += first[i];
            output += second[i];
        }
        if (second.size() < first.size()) {
            output += first[second.size()];
        }
    }

    int abs(int x) {
        if (x < 0) {
            return -x;
        }
        return x;
    }

public:
    string reformat(string s) {
        string digitOnly, alphaOnly;
        fillDigitOnly(s, digitOnly);
        fillAlphaOnly(s, alphaOnly);
        string output = "";
        if (1 < abs(digitOnly.size() - alphaOnly.size())) {
            return "";
        }
        if (digitOnly.size() < alphaOnly.size()) {
            fillOutput(alphaOnly, digitOnly, output);
        } else {
            fillOutput(digitOnly, alphaOnly, output);
        }
        return output;
    }
};
