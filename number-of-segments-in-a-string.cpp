class Solution {
public:
    int countSegments(string s) {
        int segments = 0;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            if (s[right] == ' ') {
                if (left < right) {
                    segments++;
                }
                left = right + 1;
            }
            right++;
        }
        if (left < right) {
            segments++;
        }
        return segments;
    }
};
