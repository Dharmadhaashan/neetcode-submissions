class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(c.begin(), c.end());
        backtrack(res,c,target,0,temp);
        set<vector<int>>r;
        for(vector i:res){
            r.insert(i);
        }
        vector<vector<int>>ans;
        for(auto i:r){
            ans.push_back(i);
        }
        return ans;
    }
    void backtrack(vector<vector<int>>&res,vector<int>& c,int target,int start,vector<int>temp){
        if(target<0){
            return;
        }
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<c.size();i++){
            if(c[i] > target) break;
            temp.push_back(c[i]);
            backtrack(res,c,target-c[i],i+1,temp);
            temp.pop_back();
        }
    }
};
