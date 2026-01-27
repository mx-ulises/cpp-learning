class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int rowCount = getRowCount(nums);
        vector<vector<int>> matrix = vector<vector<int>>(rowCount);
        int rowIndex = 1;
        int numsIndex = 1;
        matrix[0].push_back(nums[0]);
        while (numsIndex < nums.size()) {
            rowIndex = getNextRowIndex(nums, numsIndex, rowIndex);
            matrix[rowIndex].push_back(nums[numsIndex]);
            rowIndex++;
            numsIndex++;
        }
        return matrix;
    }

    int getRowCount(const vector<int>& nums) {
        int currentRowCount = 1;
        int maxRowCount = 1;
        int numsIndex = 1;

        while (numsIndex < nums.size()) {
            if (nums[numsIndex - 1] != nums[numsIndex]) {
                currentRowCount = 0;
            }
            currentRowCount++;
            maxRowCount = max(maxRowCount, currentRowCount);
            numsIndex++;
        }
        return maxRowCount;
    }

    int getNextRowIndex(const vector<int>& nums, int numsIndex, int rowIndex) {
        if (nums[numsIndex - 1] != nums[numsIndex]) {
            rowIndex = 0;
        }
        return rowIndex;
    }
};
