class Solution {
private:
    int charToDigit(char c) {
        return c - '0';
    }

    char digitToChar(int d) {
        return '0' + d;
    }

public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string num = "";
        while (0 <= i || 0 <= j) {
            if (0 <= i) carry += charToDigit(num1[i--]);
            if (0 <= j) carry += charToDigit(num2[j--]);
            num += digitToChar(carry % 10);
            carry /= 10;
        }
        if (carry != 0) num += digitToChar(carry);
        reverse(num.begin(), num.end());
        return num;
    }
};
