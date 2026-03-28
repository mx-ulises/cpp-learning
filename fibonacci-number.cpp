class Solution {
private:
    void updateFib(int& prev, int& current) {
        int aux = current + prev;
        prev = current;
        current = aux;
    }

public:
    int fib(int n) {
        if (n == 0) return 0;
        int prev = 0, current = 1;
        for (int i = 1; i < n; i++) {
            updateFib(prev, current);
        }
        return current;
    }
};
