class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int r=0;
        for(int i=0;i<n;i++){
            if(piles[i]>r){
                r=piles[i];
            }
        }
        int low = 1;
        int high = r;
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            long long hour =0;
            for(int p:piles){
                if(p%mid == 0){
                    hour = hour + p/mid;
                }
                else{
                    hour = hour + (p/mid)+1;
                }

            }
            if(hour<=h){
                ans=mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};
