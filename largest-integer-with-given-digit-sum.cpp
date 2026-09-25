class Solution {
public:
    int largestInteger(int n, int s) {
        int num = 0;
        int digit = 0;
        while (0 < n) {
            digit = min(9, s);
            s -= digit;
            num = 10 * num + digit;
            n--;
        }
        if (0 < s) return -1;
        return num;
    }
};
