class Solution {
private:
    void fillStrings(string& prefix, char target, vector<string>& output) {
        for (char c = 'a'; c <= target; c++) {
            output.push_back(prefix + c);
        }
    }

public:
    vector<string> stringSequence(string target) {
        string prefix = "";
        vector<string> output;
        for (char c : target) {
            fillStrings(prefix, c, output);
            prefix = output[output.size() - 1];
        }
        return output;
    }
};
