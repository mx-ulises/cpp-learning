class Solution {
private:
    int getTotalSum(int n) {
        return n * (n + 1) / 2;
    }

    int getDivisibleSum(int n, int m) {
        int divisibleSum = 0;
        int divisibleNum = m;
        while (divisibleNum <= n) {
            divisibleSum += divisibleNum;
            divisibleNum += m;
        }
        return divisibleSum;
    }

public:
    int differenceOfSums(int n, int m) {
        int totalSum = getTotalSum(n);
        int divisibleSum = getDivisibleSum(n, m);
        int nonDisvisibleSum = totalSum - divisibleSum;
        return nonDisvisibleSum - divisibleSum;
    }
};
