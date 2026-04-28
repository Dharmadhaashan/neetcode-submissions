class Solution {
public:
    int maxProfit(vector<int>& p) {
        int prev = p[0];
        int maxi = 0;
        for(int i=0;i<p.size();i++){
            if(prev>p[i]){
                prev = p[i];
            }
            else if(p[i]-prev > maxi){
                maxi = p[i]-prev;
            }
        }
        return maxi;
    }
};
