class Solution {
private:
    bool isCombinationValid(int k, int n) {
        return k == 0 && n == 0;
    }

    bool isCombinationInvalid(int k, int n) {
        return k == 0 || n <= 0;
    }
    void getCombinations(vector<vector<int>>& combinations, vector<int>& combination, int k, int n, int start) {
        if (isCombinationValid(k, n)) {
            combinations.push_back(combination);
            return;
        }
        if (isCombinationInvalid(k, n)) return;
        k--;
        for (int i = start; i < 10; i++) {
            combination.push_back(i);
            getCombinations(combinations, combination, k, n - i, i + 1);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> combination;
        getCombinations(combinations, combination, k, n, 1);
        return combinations;
    }
};
