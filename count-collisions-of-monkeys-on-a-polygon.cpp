class Solution {
public:
    int monkeyMove(int n) {
        long moves = 1, base = 2;
        int mod = 1000000007;
        while (n) {
            if (n & 1) {
                moves = (moves * base) % mod;
            }
            base = (base * base) % mod;
            n >>= 1;
        }
        moves -= 2;
        if (moves < 0) {
            moves += mod;
        }
        return moves;
    }
};
