class MinStack {
public:
    stack<pair<int,int>>stk;
    int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(val<=mini){
            mini=val;
        }
        stk.push({val,mini});
    }
    
    void pop() {
        stk.pop();
        if (!stk.empty()) {
            mini = stk.top().second;
        } 
        else {
            mini = INT_MAX;
        }
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};
