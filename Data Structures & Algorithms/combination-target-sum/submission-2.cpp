class Solution {
public:
    vector<vector<int>>ans;
    void func(vector<int>& nums,int target,int i,vector<int>& temp){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }
        if(target<0){
            return;
        }
        for(int j = i;j<nums.size();j++){
            temp.push_back(nums[j]);
            func(nums,target-nums[j],j,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        func(nums,target,0,temp);
        return ans;
    }
};
