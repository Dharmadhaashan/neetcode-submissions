class Solution {
public:
    vector<vector<int>>ans;
    void func(vector<int>n,int i,vector<int>& temp){
        ans.push_back(temp);
        for(int j = i;j<n.size();j++){
            temp.push_back(n[j]);
            func(n,j+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        func(nums,0,temp);
        return ans;
    }
};
