class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int maxi = 200;
        for(string s:strs){
            maxi = min(maxi,(int)s.size());
        }
        for(int i=0;i<maxi;i++){
            bool flag = true;
            char k = strs[0][i];
            for(string s:strs){
                if(s[i]!=k){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                break;
            }
            ans += k;
        }
        return ans;
    }
};