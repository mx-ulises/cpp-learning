class Solution {
private:
    void fillWordContainer(const string& s, stack<string>& c) {
        string current = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (0 < current.size()) c.push(current);
                current = "";
            } else {
                current += s[i];
            }
        }
        if (0 < current.size()) c.push(current);
    }

    void joinWordsInOutput(string& output, stack<string>& c) {
        while (!c.empty()) {
            if (0 < output.size()) {
                output += " ";
            }
            output += c.top();
            c.pop();
        }
    }

public:
    string reverseWords(string s) {
        stack<string> c;
        fillWordContainer(s, c);
        string output = "";
        joinWordsInOutput(output, c);
        return output;
    }
};
