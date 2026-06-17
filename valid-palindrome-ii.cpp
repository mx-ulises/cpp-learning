class Solution {
private:
    bool validPalindromeDeleteLeft(string& s) {
        bool deleted = false;
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                if (deleted) {
                    return false;
                }
                deleted = true;
            } else {
                right--;
            }
            left++;
        }
        return true;
    }

    bool validPalindromeDeleteRight(string& s) {
        bool deleted = false;
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                if (deleted) {
                    return false;
                }
                deleted = true;
            } else {
                left++;
            }
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        return validPalindromeDeleteLeft(s) || validPalindromeDeleteRight(s);
    }
};
