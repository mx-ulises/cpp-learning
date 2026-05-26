class Solution {
private:
    bool pushable(char c, unordered_map<char, char>& parenthesesMap) {
        return parenthesesMap.contains(c);
    }

    bool popable(vector<char>& container, char c, unordered_map<char, char>& parenthesesMap) {
        return 0 < container.size() && parenthesesMap[container.back()] == c;
    }

public:
    bool isValid(string s) {
        unordered_map<char, char> parenthesesMap;
        parenthesesMap['('] = ')';
        parenthesesMap['['] = ']';
        parenthesesMap['{'] = '}';
        vector<char> container;
        for (auto c : s) {
            if (pushable(c, parenthesesMap)) {
                container.push_back(c);
            } else if (popable(container, c, parenthesesMap)) {
                container.pop_back();
            } else {
                return false;
            }
        }
        return container.size() == 0;
    }
};
