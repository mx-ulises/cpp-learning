class Solution {
public:
    int residuePrefixes(string s) {
        vector<bool> visited(26);
        int different = 0;
        int output = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (!visited[c]) {
                visited[c] = true;
                different++;
            }
            if (different == (i + 1) % 3) {
                output++;
            }
        }
        return output;
    }
};
