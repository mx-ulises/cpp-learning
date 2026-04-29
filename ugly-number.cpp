class Solution {
private:
    int removeFactor(int n, int factor) {
        while ((n % factor) == 0)
            n /= factor;
        return n;
    }

public:
    bool isUgly(int n) {
        if (n == 0) return false;
        const vector<int> factors{2, 3, 5};
        for(int factor: factors)
            n = removeFactor(n, factor);
        return n == 1;
    }
};
