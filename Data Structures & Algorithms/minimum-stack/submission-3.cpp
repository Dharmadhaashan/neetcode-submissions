class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int,int>>st;
    int mini = INT_MAX;
    void push(int val) {
        mini = min(mini,val);
        st.push({val,mini});
    }
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
