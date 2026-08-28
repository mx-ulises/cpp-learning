/*

111110
111110
111110
000001

111110
122220
12333
0


*/



class Solution {
private:
    void fillMatrixNum(vector<vector<char>>& matrix, vector<vector<int>>& matrixNum) {
        for (int i = 0; i < matrix.size(); i++) {
            matrixNum.push_back(vector<int>(matrix[i].size()));
            for (int j = 0; j < matrix[i].size(); j++) {
                matrixNum[i][j] = matrix[i][j] - '0';
            }
        }
    }

    int getValue(vector<vector<int>>& matrix, int i, int j) {
        if (i < 0 || j < 0) return 0;
        return matrix[i][j];
    }

    void updateMatrixCell(vector<vector<int>>& matrix, int i, int j) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = getValue(matrix, i - 1, j - 1);
            matrix[i][j] = min(matrix[i][j], getValue(matrix, i, j - 1));
            matrix[i][j] = min(matrix[i][j], getValue(matrix, i - 1, j));
            matrix[i][j]++;
        }
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maximal = 0;
        vector<vector<int>> matrixNum;
        fillMatrixNum(matrix, matrixNum);
        for (int i = 0; i < matrixNum.size(); i++) {
            for (int j = 0; j < matrixNum[i].size(); j++) {
                updateMatrixCell(matrixNum, i, j);
                maximal = max(maximal, int(matrixNum[i][j]));
            }
        }
        return maximal * maximal;
    }
};
