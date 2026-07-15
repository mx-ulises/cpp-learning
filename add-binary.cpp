class Solution {
private:
    char getChar(int i) {
        return '0' + i;
    }


    int getBit(char c) {
        return c - '0';
    }

public:
    string addBinary(string a, string b) {
        string c = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (0 <= i || 0 <= j) {
            if (0 <= i) {
                carry += getBit(a[i]);
                i--;
            }
            if (0 <= j) {
                carry += getBit(b[j]);
                j--;
            }
            c += getChar(carry & 1);
            carry >>= 1;
        }
        if (carry == 1) {
            c += getChar(carry);
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
