class Solution {
public:
    int rob(vector<int>& n) {
        vector<int>dp(n.size(),-1);
        dp[0]=n[0];
        int neg = 0;
        for(int i=1;i<n.size();i++){
            int pick = n[i];
            if(i-2>=0){
                pick += dp[i-2];
            }
            int npick = dp[i-1];
            dp[i]=max(pick,npick);
        }
        return dp[n.size()-1];
    }
};
