class Solution {
public:
    int maxProfit(vector<int>& p) {
        vector<int>suffix;
        int maxi = 0;
        for(int i=p.size()-1;i>=0;i--){
            maxi = max(maxi,p[i]);
            suffix.push_back(maxi);
        }
        reverse(suffix.begin(),suffix.end());
        int ans = 0;
        for(int i=0;i<p.size();i++){
            ans = max(ans,suffix[i] - p[i]);
        }
        return ans;
    }
};
