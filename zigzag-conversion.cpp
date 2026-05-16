class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> rows(numRows);
        int direction = 1, i = 0;
        for(char c : s) {
            rows[i].push_back(c);
            i += direction;
            if (i < 0) {
                i = 1;
                direction = 1;
            }
            if (i == numRows) {
                i = numRows - 2;
                direction = -1;
            }
        }
        string output;
        for (string row : rows) {
            output += row;
        }
        return output;
    }
};
