class MinStack {
public:
    stack<int> s,tmp;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(tmp.empty())
            tmp.push(val);
        else
        {
            if(tmp.top()>val)
                tmp.push(val);
            else
                tmp.push(tmp.top());
        }
    }
    
    void pop() {
        if(tmp.size()!=0)
        {
            tmp.pop();
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return tmp.top();
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