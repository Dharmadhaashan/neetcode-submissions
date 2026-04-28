class Solution {
public:
    int func(int i,vector<int>& n,vector<int>& dp){
        if(dp[i]!=-1){
            return dp[i];
        }
        if(i==0){
            return dp[0]=n[0];
        }
        if(i<0){
            return 0;
        }
        int pick = n[i]+func(i-2,n,dp);
        int npick = func(i-1,n,dp);

        return dp[i]=max(pick,npick);
    }
    int rob(vector<int>& n) {
        vector<int>dp(n.size(),-1);
        return func(n.size()-1,n,dp);
    }
};
