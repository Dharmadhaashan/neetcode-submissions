class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l = 0;
        int r = n-1;
        int left_max = 0;
        int right_max = 0;
        int water =0;
        while(l<r){
            if(h[l]<h[r]){
                if(h[l]>left_max){
                    left_max = h[l];
                }
                else{
                    water += left_max - h[l];
                }
                l++;
            }
            else{
                if(h[r]>right_max){
                    right_max = h[r];
                }
                else{
                    water += right_max-h[r];
                }
                r--;
            }
        }
        return water;
    }
};
