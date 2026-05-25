class Solution {
private:
    bool isValid(string& s, int i, char target) {
        return i < s.size() && s[i] == target;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        bool valid = true;
        while(valid) {
            for (auto& s : strs) {
                valid &= isValid(s, i, strs[0][i]);
            }
            i++;
        }
        return strs[0].substr(0, i - 1);
    }
};
