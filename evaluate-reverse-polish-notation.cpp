class Solution {
private:
    int pop(stack<int>& s) {
        int x = s.top();
        s.pop();
        return x;
    }

    int runSum(stack<int>& s) {
        return pop(s) + pop(s);
    }

    int runSub(stack<int>& s) {
        int aux = pop(s);
        return pop(s) - aux;
    }

    int runMul(stack<int>& s) {
        return pop(s) * pop(s);
    }

    int runDiv(stack<int>& s) {
        int aux = pop(s);
        return pop(s) / aux;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const auto& token : tokens) {
            if (token == "+") s.push(runSum(s));
            else if (token == "-") s.push(runSub(s));
            else if (token == "*") s.push(runMul(s));
            else if (token == "/") s.push(runDiv(s));
            else s.push(stoi(token));
        }
        return s.top();
    }
};
