class Solution {
    public:
        int numberOfMatches(int teams) {
            int matches = 0;
            while (1 < teams) {
                matches += teams / 2;
                teams = (teams / 2) + (teams & 1);
            }
            return matches;
        }
    };
