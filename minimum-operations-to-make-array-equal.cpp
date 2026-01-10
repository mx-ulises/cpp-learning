class Solution {
public:
    int minOperations(int n) {
        int total = 0;
        int left = 1;
        int right = 2 * (n - 1) + 1;
        int mid = (left + right) / 2;
        while (left < mid) {
            total += mid - left;
            left += 2;
        }
        return total;
    }
};
