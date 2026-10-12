class Solution {
private:
    void shift(vector<int>& previous, int fib) {
        for (int i = 1; i < previous.size(); i++) {
            previous[i - 1] = previous[i];
        }
        previous[previous.size() - 1] = fib;
    }

    int getSum(vector<int>& previous) {
        int sum = 0;
        for (int x: previous) {
            sum += x;
        }
        return sum;
    }

    int getFib(vector<int>& previous) {
        int last = previous.size() - 1;
        return previous[last] + previous[last - 1];
    }

public:
    bool threeFibonacciSum(int n) {
        vector<int> previous({0, 1, 1});
        int fib = getFib(previous);
        while (getSum(previous) < n) {
            shift(previous, fib);
            fib = getFib(previous);
        }
        return getSum(previous) == n;
    }
};
