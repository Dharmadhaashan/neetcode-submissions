class Solution {
public:
    int func(string s,string p,int i,int j,vector<vector<int>>& dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j]){
            return dp[i][j] = func(s,p,i-1,j-1,dp);
        }
        int ans1 = 1 + func(s,p,i,j-1,dp);
        int ans2 = 1 + func(s,p,i-1,j,dp);
        int ans3 = 1 + func(s,p,i-1,j-1,dp);
        return dp[i][j] = min({ans1,ans2,ans3});
    }
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = func(word1,word2,word1.size()-1,word2.size()-1,dp);
        return ans;
    }
};
