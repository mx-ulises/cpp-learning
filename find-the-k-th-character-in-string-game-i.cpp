/*
a = 1
b = 2
bc = 3, 4
bccd = 5, 6, 7, 8
bccdcdde = 9, 10, 11, 12, 13, 14, 15, 16
*/

class Solution {
private:
    int log(int k) {
        int l = 1;
        while (l < k) {
            l <<= 1;
        }
        return l >> 1;
    }

public:
    char kthCharacter(int k) {
        char c = 'a';
        while (1 < k) {
            k -= log(k);
            c++;
        }
        return c;
    }
};
