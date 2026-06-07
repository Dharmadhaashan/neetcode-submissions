class Solution {
public:
    int func(vector<int>& nums,int i,int prev){
        if(i>=nums.size()){
            return 0;
        }
        int take =0;
        int nottake = func(nums,i+1,prev);
        if(prev==-1 || nums[i]>nums[prev]){
            take = 1+func(nums,i+1,i);
        }
        return max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = func(nums,0,-1);
        return ans;
    }
};
