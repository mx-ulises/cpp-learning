class Solution {
private:
    bool zeroMoveAway(int deltaX, int deltaY) {
        // Same position
        return deltaX == 0 && deltaY == 0;
    }

    bool oneMoveAway(int deltaX, int deltaY) {
        if (deltaX == 0) return true; // Same Column
        if (deltaY == 0) return true; // Same Rowl
        if (abs(deltaX) == abs(deltaY)) return true; // Same Diagona
        return false; // Not one move away
    }

public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int deltaX = source[0] - target[0];
        int deltaY = source[1] - target[1];
        if (zeroMoveAway(deltaX, deltaY)) return 0;
        if (oneMoveAway(deltaX, deltaY)) return 1;
        return 2;
    }
};
