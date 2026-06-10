class MyStack {
private:
     queue<int> q;
public:    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int x = q.back();
        for (int i = 1; i < q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
        return x;        
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
