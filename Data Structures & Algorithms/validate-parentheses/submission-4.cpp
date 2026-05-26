class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char i : s) {
            if(i == '(' || i == '[' || i == '{') {
                st.push(i);
            }
            else {
                // Check if stack is empty first
                if(st.empty()) {
                    return false;
                }

                char j = st.top();

                if((j == '(' && i == ')') ||
                   (j == '[' && i == ']') ||
                   (j == '{' && i == '}')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};