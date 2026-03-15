class Solution {
private:
    char shift(char c, char x) {
        return c + x - '0';
    }

public:
    string replaceDigits(string s) {
        for(int i = 0; i < s.size(); i += 2) {
            int j = i + 1;
            s[j] = shift(s[i], s[j]); 
        }
        return s;
    }
};
