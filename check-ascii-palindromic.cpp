class Solution {
private:
    bool palindromic(char a, char b) {
        if (a == 'f' && b == 'f') return true;
        if (min(a, b) == 'n' && max(a, b) == 'v') return true;
        return false;
    }

public:
    bool isPalindromic(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (palindromic(s[left], s[right]) == false) return false;
            left++;
            right--;
        }
        return true;
    }
};
