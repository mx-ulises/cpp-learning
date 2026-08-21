class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> substringCount;
        if (s.size() < 10) return {};
        for (int i = 9; i < s.size(); i++) {
            string substring = s.substr(i - 9, 10);
            if (!substringCount.count(substring)) {
                substringCount[substring] = 0;
            }
            substringCount[substring]++;
        }
        vector<string> output;
        for (const auto& [substring, count] : substringCount) {
            if (1 < count) {
                output.push_back(substring);
            }
        }
        return output;
    }
};
