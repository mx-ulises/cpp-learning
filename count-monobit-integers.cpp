class Solution {
public:
    int countMonobit(int n) {
        int monobits = 0;
        int current = 1;
        n++;
        while (current <= n) {
            monobits++;
            current <<= 1;
        }
        return monobits;
    }
};
