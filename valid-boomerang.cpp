class Solution {
private:
    bool areDistinct(const vector<int>& point1, const vector<int>& point2) {
        return (point1[0] != point2[0]) || (point1[1] != point2[1]);
    }

    bool areDistinct(const vector<vector<int>>& points) {
        bool ab = areDistinct(points[0], points[1]);
        bool ac = areDistinct(points[0], points[2]);
        bool bc = areDistinct(points[1], points[2]);
        return  ab && ac && bc;
    }

    bool isInf(const vector<int>& point1, const vector<int>& point2) {
        return (point1[1] - point2[1]) == 0;
    }

    float slope(const vector<int>& point1, const vector<int>& point2) {
        float a = point1[0] - point2[0];
        float b = point1[1] - point2[1];
        return a / b;
    }

    bool isStraightLine(const vector<vector<int>>& points) {
        bool ab = isInf(points[0], points[1]);
        bool bc = isInf(points[1], points[2]);
        if (ab && bc) return true;
        if (ab || bc) return false;
        return slope(points[0], points[1]) == slope(points[1], points[2]);
    }

public:
    bool isBoomerang(vector<vector<int>>& points) {
        return areDistinct(points) && !isStraightLine(points);
    }
};
