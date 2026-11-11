class Solution {
private:
    void swap(string& s, int i, int j) {
        char aux = s[j];
        s[j] = s[i];
        s[i] = aux;
    }

    bool sameParity(int a, int b) {
        return (a & 1) == (b & 1);
    }

public:
    string getSmallestString(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            int j = i + 1;
            if (sameParity(s[i], s[j]) && s[j] < s[i]) {
                swap(s, i, j);
                return s;
            }
        }
        return s;
    }
};
