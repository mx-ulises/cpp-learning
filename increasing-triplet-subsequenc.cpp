class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x = 2147483647;
        int y = 2147483647;
        for (int num : nums) {
            if (num <= x) {
                x = num;
            } else if (num <= y) {
                y = num;
            } else {
                return true;
            }
        }
        return false;
    }
};
