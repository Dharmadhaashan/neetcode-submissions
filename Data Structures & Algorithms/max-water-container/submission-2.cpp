class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0,r=h.size()-1;
        int max=0;
        while(l<=r){
            int m;
            if(h[l]>h[r]){
                m=(r-l)*h[r];
                r--;
            }
            else{
                m=(r-l)*h[l];
                l++;
            }
            if(m>max){
                max=m;
            }
            /*else{
                if(h[l]>h[r]){
                    r--;
                }
                else{
                    l++;
                }
            }*/
        }
        return max;
    }
};
