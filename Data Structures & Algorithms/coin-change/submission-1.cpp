class Solution {
public:
    // int func(int ind, int target, vector<int> &n,vector<vector<int>>& dp){
    //     if(ind ==0){
    //         if(target % n[0] == 0) return target/n[0];
    //         return 1e9;
    //     }
    //     if(dp[ind][target] != -1){
    //         return dp[ind][target];
    //     }
    //     int nottake = func(ind-1,target,n,dp);
    //     int take = 1e9;
    //     if(n[ind]<=target){
    //         take = 1+func(ind,target-n[ind],n,dp);
    //     }
    //     return dp[ind][target]=min(take,nottake);
    // }
    int coinChange(vector<int>& c, int amount) {
        int n = c.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        for (int T = 0; T <= amount; T++) {
            if (T % c[0] == 0)
                dp[0][T] = T / c[0];
            else
                dp[0][T] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int T = 0; T <= amount; T++) {
                int nottake = dp[i - 1][T];
                int take = 1e9;
                if (c[i] <= T) {
                    take = 1 + dp[i][T - c[i]];
                }
                dp[i][T] = min(take, nottake);
            }
        }

        int ans = dp[c.size()-1][amount];
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};
