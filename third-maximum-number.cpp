class Solution {
private:
    int MINIMAL = -2147483648;

    void updateMaximals(vector<int>& maximals, int num, int i) {
        if (maximals[i] < num) {
                maximals[max(0, i - 1)] = maximals[i];
                maximals[i] = num;
            }
    }

public:
    int thirdMax(vector<int>& nums) {
        vector<int> maximals({MINIMAL, MINIMAL, MINIMAL});
        unordered_set<int> visited;
        for (int num : nums) {
            if (visited.find(num) != visited.end()) {
                continue;
            }
            visited.insert(num);
            updateMaximals(maximals, num, 0);
            updateMaximals(maximals, num, 1);
            updateMaximals(maximals, num, 2);
        }
        if (visited.size() < 3) return maximals[2];
        return maximals[0];
    }
};