class Solution {
private:
    bool inRange(int start, int x, int end) {
        return start <= x && x <= end;
    }

    bool exist(vector<vector<int>>& grid, int i, int j) {
        return inRange(0, i, grid.size() - 1) && inRange(0, j, grid[i].size() - 1);
    }

    bool checkBelow(vector<vector<int>>& grid, int i, int j) {
        return !exist(grid, i + 1, j) || grid[i][j] == grid[i + 1][j];
    }

    bool checkRight(vector<vector<int>>& grid, int i, int j) {
        return !exist(grid, i, j + 1) || grid[i][j] != grid[i][j + 1];
    }

    bool isValid(vector<vector<int>>& grid, int i, int j) {
        return checkBelow(grid, i, j) && checkRight(grid, i, j);
    }

public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!isValid(grid, i, j)) return false;
            }
        }
        return true;
    }
};
