class Solution {
private:
    int sum(vector<int>& edges) {
        int degree = 0;
        for (auto edge : edges) {
            degree += edge;
        }
        return degree;
    }

public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> degrees(matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            degrees[i] = sum(matrix[i]);
        }
        return degrees;
    }
};
