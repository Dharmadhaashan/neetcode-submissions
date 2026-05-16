class Solution {
public:
    int trap(vector<int>& h) {
        vector<int>prefix;
        prefix.push_back(-1);
        int maxi = h[0];
        for(int i=1;i<h.size();i++){
            if(h[i]>=maxi){
                prefix.push_back(-1);
                maxi = h[i];
            }
            else{
                prefix.push_back(maxi);
            }
        }
        vector<int>suffix;
        suffix.push_back(-1);
        maxi = h[h.size()-1];
        for(int i=h.size()-2;i>=0;i--){
            if(h[i]>=maxi){
                suffix.push_back(-1);
                maxi = h[i];
            }
            else{
                suffix.push_back(maxi);
            }
        }
        reverse(suffix.begin(),suffix.end());
        int ans = 0;
        for(int i=0;i<h.size();i++){
            if(suffix[i]==-1 || prefix[i]==-1){
                continue;
            }
            else{
                int sum = min(suffix[i],prefix[i]);
                sum -= h[i];
                ans += sum;
            }
        }
        return ans;
    }
};
