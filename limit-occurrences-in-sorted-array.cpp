class Solution {
private:
    int updateCurrentRepetitions(int current, int prev, int currentRepetitions) {
        if (current != prev) {
            currentRepetitions = 0;
        }
        return currentRepetitions + 1;
    }

public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int currentRepetitions = 0;
        vector<int> output;
        int prev = 0;
        for (int num : nums) {
            currentRepetitions = updateCurrentRepetitions(num, prev, currentRepetitions);
            if (currentRepetitions <= k) {
                output.push_back(num);
            }
            prev = num;
        }
        return output;
    }
};
