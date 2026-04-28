class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> a;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != "+" && t[i] != "-" && t[i] != "*" && t[i] != "/") {
                int num = stoi(t[i]);
                a.push(num);
            } 
            else {
                int num2 = a.top();
                a.pop();
                int num1 = a.top();
                a.pop();
                if (t[i] == "+") {
                    a.push(num1 + num2);
                } 
                else if (t[i] == "-") {
                    a.push(num1 - num2);
                } 
                else if (t[i] == "*") {
                    a.push(num1 * num2);
                } 
                else {
                    a.push(num1 / num2);
                }
            }
        }
        return a.top();
    }
};
