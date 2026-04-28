class Solution {
public:
    int func(int i,vector<int>& c,int amount){
        if(i==0){
            if(amount%c[0]==0) return amount/c[0];
            return 1e9;
        }
        int nottake = func(i-1,c,amount);
        int take = 1e9;
        if(c[i]<=amount){
            take = 1+func(i,c,amount-c[i]);
        }
        return min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = func(coins.size()-1,coins,amount);
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};
