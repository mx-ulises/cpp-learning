class Solution {
private:
    bool isAlphaNumeric(char c) {
        if ('0' <= c && c <= '9') return true;
        if ('A' <= c && c <= 'Z') return true;
        if ('a' <= c && c <= 'z') return true;
        return false;
    }

    char lower(char c) {
        if ('A' <= c && c <= 'Z') {
            return 'a' + c - 'A';
        }
        return c;
    }

public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            if (isAlphaNumeric(s[left]) == false) {
                left++;
            } else if (isAlphaNumeric(s[right]) == false) {
                right--;
            } else if (lower(s[left]) == lower(s[right])) {
                left++;
                right--;
            } else {
                return false;
            }

        }
        return true;
    }
};
