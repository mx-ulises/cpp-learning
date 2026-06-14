class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0;
        int vertical = 0;
        for (auto move : moves) {
            switch (move) {
                case 'U':
                    vertical--;
                    break;
                case 'D':
                    vertical++;
                    break;
                case 'L':
                    horizontal++;
                    break;
                case 'R':
                    horizontal--;
                    break;
            }
        }
        return horizontal == 0 && vertical == 0;
    }
};
