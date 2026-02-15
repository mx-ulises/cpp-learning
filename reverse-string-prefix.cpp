class Solution {
private:
    void swapAndMove(string & s, int & left, int & right) {
        swap(s, left, right);
        left++;
        right--;
    }

    void swap(string & s, int left, int right) {
        char aux = s[left];
        s[left] = s[right];
        s[right] = aux;
    }

public:
    string reversePrefix(string s, int k) {
        int left = 0;
        int right = k - 1;
        while (left < right) {
            swapAndMove(s, left, right);
        }
        return s;
    }
};
