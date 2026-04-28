class Solution {
public:
    vector<int> twoSum(vector<int>& n, int tar) {
        int l=0,r=n.size()-1;
        while(l<r){
            int cur=n[r]+n[l];
            if(cur<tar){
                l++;
            }
            else if(cur>tar){
                r--;
            }
            else{
                return {l+1,r+1};
            }
        }
        return {};
    }
};
