class Solution {
private:
    int getArea(int ax1, int ay1, int ax2, int ay2) {
        return (ax2 - ax1) * (ay2 - ay1);
    }

    int lineIntersection(int a1, int a2, int b1, int b2) {
        int c1 = max(a1, b1);
        int c2 = min(a2, b2);
        return max(c2 - c1, 0);
    }

    int getIntersection(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        return lineIntersection(ax1, ax2, bx1, bx2) * lineIntersection(ay1, ay2, by1, by2);
    }

public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = getArea(ax1, ay1, ax2, ay2);
        int area2 = getArea(bx1, by1, bx2, by2);
        int intersection = getIntersection(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        return area1 + area2 - intersection;
    }
};
