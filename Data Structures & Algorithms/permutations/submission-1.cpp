class Solution {
public:
    vector<vector<int>>ans;
    void func(vector<int>& nums,vector<int>& temp,vector<int>& vis){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }
        for(int start = 0;start<nums.size();start++){
            if(!vis[start]){
                temp.push_back(nums[start]);
                vis[start] = 1;
                func(nums,temp,vis);
                temp.pop_back();
                vis[start] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<int> vis(nums.size(),0);
        func(nums,temp,vis);
        return ans;
    }
};
