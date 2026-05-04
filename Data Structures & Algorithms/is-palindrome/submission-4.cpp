class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j= s.size()-1;
        for (auto& x : s) {
            x = tolower(x);
        }
        while(i<=j){
            if(!isalnum(s[i])){
                i++;
            }
            else if(!isalnum(s[j])){
                j--;
            }
            else{
                if(s[i]!=s[j]){
                    return 0;
                }
                i++;
                j--;
            }
        }
        return 1;
    }
};
