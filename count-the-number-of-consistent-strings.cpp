class Solution {
private:
    vector<bool> getAllowedChars(string & allowed) {
        vector<bool> allowedChars(26);
        for (char c : allowed) {
            allowedChars[c - 'a'] = true;
        }
        return allowedChars;
    }

    bool isConsistent(vector<bool> & allowedChars, string & word) {
        for (char c : word) {
            if (!allowedChars[c - 'a']) {
                return false;
            }
        }
        return true;
    }

public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowedChars = getAllowedChars(allowed);
        int consistentStrings =0;
        for (string word: words) {
            if (isConsistent(allowedChars, word)) {
                consistentStrings++;
            }
        }
        return consistentStrings;
    }
};
