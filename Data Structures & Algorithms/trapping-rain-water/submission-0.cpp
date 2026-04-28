class Solution {
public:
    int trap(vector<int>& h) {
        vector<int>p;
        p.push_back(h[0]);
        for(int i=1;i<h.size();i++){
            p.push_back(max(h[i],p[i-1]));
        }
        vector<int>s;
        s.push_back(h[h.size()-1]);
        for(int i=h.size()-2;i>=0;i--){
            s.push_back(max(s[h.size()-1-i-1],h[i]));
        }
        reverse(s.begin(),s.end());
        int maxi = 0;
        for(int i=0;i<h.size();i++){
            int temp = min(p[i],s[i])-h[i];
            maxi +=temp;
        }
        return maxi;
    }
};