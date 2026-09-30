class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<int> starts(101);
        vector<int> ends(101);
        for (auto& interval : intervals) {
            starts[interval[0]]++;
            ends[interval[1]]++;
        }
        int activeIntervals = 0;
        int intersectingIntervals = 0;
        for (int i = 0; i < 101; i++) {
            while (0 < starts[i]) {
                intersectingIntervals += activeIntervals;
                activeIntervals++;
                starts[i]--;
            }
            activeIntervals -= ends[i];
        }
        return intersectingIntervals;
    }
};
