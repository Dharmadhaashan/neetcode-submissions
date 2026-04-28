class Solution {
public:
    vector<int>dp;
    int numDecodings(string s) {
        dp.resize(s.size());
        dp.assign(s.size(),-1);
        return func(0,s);
    }
    int func(int i,string s){
        if(i>=s.size()) return 1;
        if(s[i]=='0') return 0;
        if(i==s.size()-1) return 1;
        if(dp[i]!=-1){
            return dp[i];
        }
        if((s[i]=='1')|| (s[i] == '2' && s[i + 1] <= '6')){
            return dp[i]=func(i+1,s)+func(i+2,s);
        }
        return dp[i]=func(i+1,s);
    }
};
