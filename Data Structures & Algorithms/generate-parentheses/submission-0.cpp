class Solution {
public:
    string stack;
    vector<string>res;

    void backtrack(int openn,int closen,int n){
        if(openn==closen && openn==n){
            res.push_back(stack);
        }
        
        if(openn<n){
            stack += '(';
            backtrack(openn+1,closen,n);
            stack.pop_back();
        }

        if(closen <openn){
            stack += ')';
            backtrack(openn,closen+1,n);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0,0,n);
        return res;
    }
};
