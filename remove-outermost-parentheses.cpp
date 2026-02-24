class Solution {
private:
    void checkBalanceAndUpdateOutput(string & output, int balance, char c) {
        if (balance) {
            output += c;
        }
    }

    int updateOutputAndBalance(string & output, int balance, char c) {
        if (c == '(') {
            checkBalanceAndUpdateOutput(output, balance++, c);
        } else {
            checkBalanceAndUpdateOutput(output, --balance, c);
        }
        return balance;
    }

public:
    string removeOuterParentheses(string s) {
        string output = "";
        int balance = 0;
        for (char c : s) {
            balance = updateOutputAndBalance(output, balance, c);
        }
        return output;
    }
};
