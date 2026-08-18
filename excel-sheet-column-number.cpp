class Solution {
public:
    int titleToNumber(string columnTitle) {
        int columnNumber = 0;
        long multiplier = 1;
        for (int i = columnTitle.size() - 1; 0 <= i; i--) {
            columnNumber +=  multiplier * (columnTitle[i] - 'A' + 1);
            multiplier *= 26;
        }
        return columnNumber;
    }
};
