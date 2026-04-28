class Solution {
public:
    set<vector<int>>res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        backtrack(nums,temp,0);
        vector<vector<int>>ans;
        for(auto i:res){
            ans.push_back(i);
        }
        return ans;
    }
    void backtrack(vector<int>& nums, vector<int>temp,int start){
        res.insert(temp);
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,temp,i+1);
            temp.pop_back();
        }
    }
};
