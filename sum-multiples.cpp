class Solution {
private:
    bool isDivisible(int i) {
        if (i % 3 && i % 5 && i % 7) {
            return false;
        }
        return true; 
    }
public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            if (isDivisible(i)) {
                sum += i;
            }
        }
        return sum;
    }
};
