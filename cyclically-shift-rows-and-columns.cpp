/*
 [1, 2, 3, 4, 5]
 [1, 2, 1, 4, 5] 3
*/

class Solution {
private:
    void shiftRow(vector<vector<int>>& grid, int i, int x) {
        vector<int> auxRow(grid.size());
        for(int j = 0; j < grid.size(); j++) {
            int auxJ = (j - x + grid.size()) % grid.size();
            auxRow[auxJ] = grid[i][j];
        }
        for(int j = 0; j < grid.size(); j++) {
            grid[i][j] = auxRow[j];
        }
    }

    void shiftCol(vector<vector<int>>& grid, int j, int x) {
        vector<int> auxCol(grid.size());
        for(int i = 0; i < grid.size(); i++) {
            int auxI = (i - x + grid.size()) % grid.size();
            auxCol[auxI] = grid[i][j];
        }
        for(int i = 0; i < grid.size(); i++) {
            grid[i][j] = auxCol[i];
        }
    }

public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for (int i = 0; i < n; i++) {
            shiftRow(grid, i, rowShift[i]);
        }
        for (int j = 0; j < n; j++) {
            shiftCol(grid, j, colShift[j]);
        }
        return grid;
    }
};
