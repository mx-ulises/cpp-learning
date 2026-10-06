class Solution {
public:
    bool checkGoodInteger(int n) {
        int difference = 0;
        vector<int> diffMap({0, 0, 2, 6, 12, 20, 30, 42, 56, 72});
        while (0 < n) {
            int d = n % 10;
            difference += diffMap[d];
            if (difference >= 50) {
                return true;
            }
            n /= 10;
        }
        return false;
    }
};
