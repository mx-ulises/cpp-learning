class Solution {
private:
    int getMaxLocal(vector<vector<int>>& grid, int rowStart, int colStart) {
        int maxLocal = 0;
        int rowEnd = rowStart + 3;
        int colEnd = colStart + 3;
        for (int i = rowStart; i < rowEnd; i++) {
            for (int j = colStart; j < colEnd; j++) {
                maxLocal = max(maxLocal, grid[i][j]);
            }
        }
        return maxLocal;
    }

    void updateRow(vector<int>& row, vector<vector<int>>& grid, int i, int n) {
        row = vector<int>(n);
        for (int j = 0; j < n; j++) {
            row[j] = getMaxLocal(grid, i, j);
        }
    }

public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size() - 2;
        vector<vector<int>> output(n);
        for (int i = 0; i < n; i++) {
            updateRow(output[i], grid, i, n);
        }
        return output;
    }
};
