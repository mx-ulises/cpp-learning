class Solution {
private:
    int getRotations(int a, int b) {
        int rotations = a - b;
        if (rotations < 0) {
            rotations += 10;
        }
        return rotations;
    }

    int getMinRotations(int start, int end) {
        int right = getRotations(start, end);
        int left = getRotations(end, start);
        return min(right, left);
    }

public:
    int minRotations(string s) {
        int start = 0;
        int totalRotations = 0;
        for (char c : s) {
            int end = c - '0';
            totalRotations += getMinRotations(start, end);
            start = end;
        }
        return totalRotations;
    }
};
