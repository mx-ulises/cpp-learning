class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> map(m);
        map[0] = string(n, '.');
        string s = string(n - 1, '#') + '.';
        for (int i = 1; i < m; i++) {
            map[i] = s;
        }
        return map;
    }
};
