class Solution {
public:
    bool isValid(string s) {
        stack<char>a;
        for(char i:s){
            if(i=='('||i=='{'||i=='['){
                a.push(i);
            }
            else{
                if(a.empty()){
                    return false;
                }
                else{
                    char temp=a.top();
                    a.pop();
                    if((i==')'&& temp=='(')||(i=='}'&& temp=='{')||(i==']'&& temp=='[')){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(a.empty()){
            return true;
        }
        return false;
    }
};
