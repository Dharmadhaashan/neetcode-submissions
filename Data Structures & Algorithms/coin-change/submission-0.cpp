class Solution {
public:
    int func(int ind, int target, vector<int> &n,vector<vector<int>>& dp){
        if(ind ==0){
            if(target % n[0] == 0) return target/n[0];
            return 1e9;
        }
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        int nottake = func(ind-1,target,n,dp);
        int take = 1e9;
        if(n[ind]<=target){
            take = 1+func(ind,target-n[ind],n,dp);
        }
        return dp[ind][target]=min(take,nottake);
    }
    int coinChange(vector<int>& c, int amount) {
        vector<vector<int>>dp(c.size(),vector<int>(amount+1,-1));
        int ans = func(c.size()-1,amount,c,dp);
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};
