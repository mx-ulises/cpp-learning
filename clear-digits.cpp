class Solution {
public:
    string clearDigits(string s) {
        vector<char> stack = vector<char>();
        for (char c : s) {
            if (isdigit(c)){
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return string(stack.begin(), stack.end());
    }
};
