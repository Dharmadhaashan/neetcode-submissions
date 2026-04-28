class Solution {
public:
    int rob(vector<int>& n) {
        int prev1 = n[0];
        int prev2 = 0;
        for(int i=1;i<n.size();i++){
            int pick = n[i]+prev2;
            int npick = prev1;
            prev2 = prev1;
            prev1 = max(pick,npick);
        }
        return prev1;
    }
};
