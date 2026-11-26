class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> visited;
        for (int i = 1; i < s.size(); i++) {
            visited.insert(s.substr(i - 1, 2));
        }
        reverse(s.begin(), s.end());
        for (int i = 1; i < s.size(); i++) {
            if (visited.count(s.substr(i - 1, 2))) return true;
        }
        return false;
    }
};
