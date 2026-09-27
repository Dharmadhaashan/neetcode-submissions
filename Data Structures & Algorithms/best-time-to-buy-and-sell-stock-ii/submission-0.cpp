class Solution {
public:
    int func(vector<int>& p,int i,bool flag,vector<vector<int>>& dp){
        if(i>=p.size()){
            return 0;
        }
        if(dp[i][flag]!= -1){
            return dp[i][flag];
        }
        if(!flag){
            int take = -p[i] + func(p,i+1,true,dp);
            int nottake = func(p,i+1,false,dp);
            return dp[i][flag] = max(take,nottake);
        }
        int sell = p[i] + func(p,i+1,false,dp);
        int notsell = func(p,i+1,true,dp);
        return dp[i][flag] = max(sell,notsell);
    }
    int maxProfit(vector<int>& p) {
        vector<vector<int>>dp(p.size(),vector<int>(2,-1));
        int ans = func(p,0,false,dp);
        return ans;
    }
};