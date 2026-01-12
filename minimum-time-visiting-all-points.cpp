class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;
        for (int i = 1; i < points.size(); i++) {
            totalTime += getTimeBetweenPoints(points[i - 1], points[i]);
        }
        return totalTime;
    }

    int getTimeBetweenPoints(vector<int>& start, vector<int>& end) {
        int verticalDistance = abs(start[0] - end[0]);
        int horizontalDistance = abs(start[1] - end[1]);
        return max(verticalDistance, horizontalDistance);
    }
};
