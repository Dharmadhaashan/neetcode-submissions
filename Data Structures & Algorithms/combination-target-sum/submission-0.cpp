class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        backtrack(res,nums,temp,0,target);
        return res;
    }
    void backtrack(vector<vector<int>>&res,vector<int>nums,vector<int>&temp,int start,int target){
        if(target<0){
            return;
        }
        if(target == 0){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(res,nums,temp,i,target - nums[i]);
            temp.pop_back();
        }
    }
};
