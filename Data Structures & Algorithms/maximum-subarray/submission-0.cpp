class Solution {
public:
    int maxSubArray(vector<int>& n) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n.size();i++){
            sum += n[i];
            maxi=max(maxi,sum);
            if(sum <0){
                sum =0;
            }
        }
        return maxi;
    }
};
