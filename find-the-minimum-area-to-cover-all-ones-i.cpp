class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minimalX = grid.size(), maximalX = -1;
        int minimalY = grid[0].size(), maximalY = -1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    minimalX = min(minimalX, i);
                    minimalY = min(minimalY, j);
                    maximalX = max(maximalX, i + 1);
                    maximalY = max(maximalY, j + 1);
                }
            }
        }
        return (maximalX - minimalX) * (maximalY - minimalY);
    }
};
