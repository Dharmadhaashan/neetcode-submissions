class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = INT_MIN;
        int i=0;
        int j=h.size()-1;
        while(i<j){
            int area = j-i;
            if(h[i]>h[j]){
                area *= h[j];
                j--;
            }
            else{
                area *= h[i];
                i++;
            }
            ans = max(ans,area);
        }
        return ans;
    }
};
