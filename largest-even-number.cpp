class Solution {
public:
    string largestEven(string s) {
        int right = s.size() - 1;
        while (0 <= right && s[right] == '1') {
            right--;
        }
        return s.substr(0, right + 1);
    }
};
