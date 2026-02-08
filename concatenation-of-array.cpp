class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n =  nums.size();
        vector<int> concatenation = vector<int>(2 * n);
        for (int i = 0; i < n; i++) {
            concatenation[i] = nums[i];
            concatenation[i + n] = nums[i];
        }
        return concatenation;
    }
};
