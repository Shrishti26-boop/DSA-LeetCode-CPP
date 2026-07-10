class MinStack {
public:
    stack<int>st,Minst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(Minst.empty()||val<=Minst.top()){
            Minst.push(val);
        }
    }
    
    void pop() {
        if(st.top()==Minst.top()){
            Minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return Minst.top();
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