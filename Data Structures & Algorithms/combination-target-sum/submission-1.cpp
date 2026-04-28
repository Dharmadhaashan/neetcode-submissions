class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        backtrack(nums,0,target,temp);
        return ans;
    }
    void backtrack(vector<int>& nums,int start,int target, vector<int> temp){
        if(target == 0){
            ans.push_back(temp);
        }
        if(target < 0){
            return ;
        }
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,i,target-nums[i],temp);
            temp.pop_back();
        }
    }
};
