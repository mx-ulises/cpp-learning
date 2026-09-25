class Solution {
private:
    int getColor(int x, int y) {
        return (x ^ y) & 1;
    }

public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return getColor(start[0], start[1]) == getColor(target[0], target[1]);
    }
};
