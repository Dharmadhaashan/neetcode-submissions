class Solution {
public:
    int func(int i,vector<int>& n,int target){
        if(i<0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        return func(i-1,n,target-n[i]) + func(i-1,n,target+n[i]);
    }
    int findTargetSumWays(vector<int>& n, int target) {
        return func(n.size()-1,n,target);
    }
};
