class Solution {
private:
    bool isMapped(unordered_map<char,char>& m, char c) {
        return m.find(c) != m.end();
    }

    bool areBothMapped(unordered_map<char,char>& m1, char c1, unordered_map<char,char>& m2, char c2) {
        return isMapped(m1, c1) & isMapped(m2, c2);
    }

   bool isOneMappedOnly(unordered_map<char,char>& m1, char c1, unordered_map<char,char>& m2, char c2) {
    return isMapped(m1, c1) ^ isMapped(m2, c2);
   }

   bool isValidMapping(unordered_map<char,char>& m1, char c1, unordered_map<char,char>& m2, char c2) {
    return m1[c1] == c2 && m2[c2] == c1;
   }

public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1, m2;
        char c1, c2;
        for (int i = 0; i < s.size(); i++) {
            c1 = s[i];
            c2 = t[i];
            if (areBothMapped(m1, c1, m2, c2) && !isValidMapping(m1, c1, m2, c2)) return false;
            if (isOneMappedOnly(m1, c1, m2, c2)) return false;
            m1[c1] = c2;
            m2[c2] = c1;
        }
        return true;
    }
};
