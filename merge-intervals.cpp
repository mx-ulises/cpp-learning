class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> output;
        vector<int> current = intervals[0];
        for (auto interval: intervals) {
            if (current[1] < interval[0]) {
                output.push_back(current);
                current = interval;
            } else {
                current[1] = max(current[1], interval[1]);
            }
        }
        output.push_back(current);
        return output;
    }
};
