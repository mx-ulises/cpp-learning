class Solution {
private:
    void findCombinations(vector<int>& candidates, int i, vector<int>& currentVector, int target, vector<vector<int>>& output) {
        if (target == 0) {
            output.push_back(currentVector);
            return;
        }
        if (target < 0 || candidates.size() == i) {
            return;
        }
        findCombinations(candidates, i + 1, currentVector, target, output);
        currentVector.push_back(candidates[i]);
        findCombinations(candidates, i, currentVector, target - candidates[i], output);
        currentVector.pop_back();
    }


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currentVector;
        vector<vector<int>> output;
        findCombinations(candidates, 0, currentVector, target, output);
        return output;
    }
};
