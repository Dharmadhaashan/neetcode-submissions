class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        sort(n.begin(),n.end());
        vector<vector<int>>res;
        for(int i=0;i<n.size();i++){
            if (i > 0 && n[i] == n[i - 1]) continue;
            int l=i+1,r=n.size()-1;
            while(l<r){
                int cur=n[l]+n[r]+n[i];
                if(cur==0){
                    res.push_back({n[l],n[r],n[i]});
                    l++;
                    r--;
                    while (l < r && n[l] == n[l - 1]) l++;
                    while (l < r && n[r] == n[r + 1]) r--;
                }
                else if(cur > 0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return res;
    }
};
