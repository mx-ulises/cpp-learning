class Solution {
private:
    long palindrome(int x) {
        long y = 0;
        while(0 < x) {
            y = (y * 10) + (x % 10);
            x /= 10;
        }
        return y;
    }

public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        return palindrome(x) == x;
    }
};
