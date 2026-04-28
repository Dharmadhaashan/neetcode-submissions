class Solution {
public:
    int rob(vector<int>& n) {
        if(n.size()==1){
            return n[0];
        }
        int prev1 = n[0];
        int prev2 = 0;
        for(int i=1;i<n.size()-1;i++){
            int pick = n[i]+prev2;
            int npick = prev1;
            prev2 = prev1;
            prev1 = max(pick,npick);
        }
        int ans1 = prev1;
        prev1 = n[1];
        prev2 = 0;
        for(int i=2;i<n.size();i++){
            int pick = n[i]+prev2;
            int npick = prev1;
            prev2 = prev1;
            prev1 = max(pick,npick);
        }
        int ans2 = prev1;
        return max(ans1,ans2);
    }
};
