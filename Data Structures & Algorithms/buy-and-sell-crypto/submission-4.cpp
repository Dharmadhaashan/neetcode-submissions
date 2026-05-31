class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mini = INT_MAX;
        int ans = 0;
        for(int i=0;i<p.size();i++){
            mini = min(mini,p[i]);
            ans = max(ans,p[i]-mini);
        }
        return ans;
    }
};
