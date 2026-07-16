class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, mid = 0, aux = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid != 0) {
                aux = x / mid;
            } else {
                aux = x;
            }
            if (aux == mid) {
                return mid;
            }
            if (mid < aux) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
