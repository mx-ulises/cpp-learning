class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int left = 0;
        int right = s.size() - 1;
        int i = 0;
        while (i <= right) {
            if (s[i] == y) {
                s[i] = s[left];
                s[left] = y;
                left++;
            }
            if (s[i] == x) {
                s[i] = s[right];
                s[right] = x;
                right--;
                i--;
            }
            i++;
        }
        return s;
    }
};
