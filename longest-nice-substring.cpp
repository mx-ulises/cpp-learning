class Solution {
private:
    void resetNiceMap(vector<int>& niceMap) {
        for (int i = 0; i < niceMap.size(); i++) {
            niceMap[i] = 0;
        }
    }

    bool isNice(const vector<int>& niceMap) {
        for(int c : niceMap) {
            if (c == 1 || c == 2) return false;
        }
        return true;
    }

    int getIndex(char c) {
        if ('A' <= c && c <= 'Z') return c - 'A';
        return c - 'a';
    }

    int getMask(char c) {
        if ('A' <= c && c <= 'Z') return 2;
        return 1;
    }

    void addToNiceMap(vector<int>& niceMap, char c) {
        niceMap[getIndex(c)] |= getMask(c);
    }

    bool isLongerSubstring(string s, int l) {
        return s.size() < l;
    }

public:
    string longestNiceSubstring(string s) {
        vector<int> niceMap(26);
        string maximalNiceSubstring = "";
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                addToNiceMap(niceMap, s[j]);
                if(isNice(niceMap) && isLongerSubstring(maximalNiceSubstring, j - i + 1)) {
                    maximalNiceSubstring = s.substr(i, j - i + 1);
                }
            }
            resetNiceMap(niceMap);
        }
        return maximalNiceSubstring;
    }
};
