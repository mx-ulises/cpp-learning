class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        pair<vector<int>,vector<int>> maxHeightsPerDirection = getMaxHeightsPerDirection(grid);
        return getMaxIncreaseKeepingSkyline(grid, maxHeightsPerDirection);
    }

    pair<vector<int>,vector<int>> getMaxHeightsPerDirection(vector<vector<int>>& grid) {
        vector<int> maxHeigthNorth = vector<int>(grid.size());
        vector<int> maxHeigthWest = vector<int>(grid.size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                maxHeigthNorth[j] = max(maxHeigthNorth[j], grid[i][j]);
                maxHeigthWest[i] = max(maxHeigthWest[i], grid[i][j]);
            }
        }
        return pair<vector<int>,vector<int>>(maxHeigthNorth, maxHeigthWest);
    }

    int getMaxIncreaseKeepingSkyline(vector<vector<int>>& grid, pair<vector<int>,vector<int>>& maxHeightsPerDirection) {
        int increases = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                increases += min(maxHeightsPerDirection.first[j], maxHeightsPerDirection.second[i]) - grid[i][j];
            }
        }
        return increases;
    }
};
