class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int>st;
        for(string i:t){
            if(i=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b+a);
            }
            else if(i=="-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b-a);
            }
            else if(i=="*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b*a);
            }
            else if(i=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};
