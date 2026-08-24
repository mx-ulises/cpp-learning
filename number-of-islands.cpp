class Solution {
private:
    bool isLand(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x == grid.size()) return false;
        if (y < 0 || y == grid[x].size()) return false;
        return grid[x][y] == '1';
    }

    bool visitIsland(vector<vector<char>>& grid, int x, int y) {
        if (isLand(grid, x, y)) {
            grid[x][y] = '0';
            visitIsland(grid, x - 1, y);
            visitIsland(grid, x + 1, y);
            visitIsland(grid, x, y + 1);
            visitIsland(grid, x, y - 1);
            return true;
        }
        return false;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                islandCount += visitIsland(grid, i, j);
            }
        }
        return islandCount;
    }
};
