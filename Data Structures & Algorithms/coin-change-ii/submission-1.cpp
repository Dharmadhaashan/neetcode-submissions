class Solution {
public:
    int func(int i,vector<int>& c,int target,vector<vector<int>>& dp){
        if(i==0){
            if(target%c[0]==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int nottake = func(i-1,c,target,dp);
        int take = 0;
        if(c[i]<=target){
            take = func(i,c,target-c[i],dp);
        }
        return dp[i][target] = nottake+take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return func(coins.size()-1,coins,amount,dp);
    }
};
