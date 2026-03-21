class Solution {
private:
    int digitSum(int x) {
        int s = 0;
        while (0 < x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    bool isSymmetric(int x, int divisor) {
        return digitSum(x / divisor) == digitSum(x % divisor);
    }

    int countSymmetricIntegersInRange(int start, int end, int divisor) {
        int count = 0;
        for (int i = start; i <= end; i++) {
            if (isSymmetric(i, divisor))
                count++;
        }
        return count;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        count += countSymmetricIntegersInRange(max(10, low), min(high, 99), 10);
        count += countSymmetricIntegersInRange(max(1000, low), high, 100);
        return count;
    }
};
