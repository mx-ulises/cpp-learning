class Solution {
private:
    char getEncryptedChar(const string& s, int i, int k) {
        int j = (i + k) % s.size();
        return s[j];
    }

public:
    string getEncryptedString(const string& s, int k) {
        string encryptedString = string(s);
        for (int i = 0; i < s.size(); i++) {
            encryptedString[i] = getEncryptedChar(s, i, k);
        }
        return encryptedString;
    }
};
