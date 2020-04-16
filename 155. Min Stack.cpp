// 155. Min Stack

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    int min_val=INT_MAX;
    MinStack() {
        while(!s.empty())
            s.pop();
        while(!mins.empty())
            mins.pop();
    }
    void push(int x) {
        s.push(x);
        if(mins.empty())
            mins.push(x);
        else if(mins.top()>=s.top())
            mins.push(x);
    }
    void pop() {
        if(s.empty())
            return;
        int x=s.top();
        s.pop();
        if(x==mins.top())
            mins.pop();
    }
    int top() {
        if(s.empty())
            return -1;
        return s.top();
    }
    int getMin() {
        if(mins.empty())
            return -1;
        return mins.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */