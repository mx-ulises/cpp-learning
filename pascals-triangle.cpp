class Solution {
private:
    void addRow(vector<vector<int>>& output, vector<int>& prev) {
        vector<int> row(prev.size() + 1);
        row[0] = prev[0];
        row[row.size() - 1] = prev[prev.size() - 1];
        for (int i = 1; i < prev.size(); i++) {
            row[i] = prev[i - 1] + prev[i];
        }
        output.push_back(row);
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output({{1}});
        for(int i = 1; i < numRows; i++) {
            addRow(output, output[i - 1]);
        }
        return output;
    }
};
