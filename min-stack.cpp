class MinStack {
private:
    vector<int> stack;
    vector<int> minStack;

public:
    MinStack() {

    }
    
    void push(int val) {
        stack.push_back(val);
        if (minStack.size() == 0 || val <= minStack[minStack.size() - 1]) {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if (top() == getMin()) {
            minStack.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        return minStack[minStack.size() - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
