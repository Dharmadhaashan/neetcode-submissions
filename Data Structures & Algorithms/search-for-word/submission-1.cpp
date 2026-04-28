class Solution {
public:
    bool flag = false;
    bool exist(vector<vector<char>>& b, string w) {
        vector<vector<int>>vis(b.size(),vector<int>(b[0].size(),0));
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(b[i][j]==w[0]){
                    if(w.size()==1){
                        return true;
                    }
                    func(b,i,j,w,1,vis);
                    if(!flag){
                        vis.assign(b.size(), vector<int>(b[0].size(), 0));
                    }
                }
            }
        }
        return flag;
    }
    void func(vector<vector<char>>& b,int i,int j,string w, int curr,vector<vector<int>>& vis){
        if(curr == w.size()){
            flag = true;
            return;
        }
        vis[i][j]=1;
        if(i-1>=0 && b[i-1][j]==w[curr] && !flag && !vis[i-1][j]){
            func(b,i-1,j,w,curr+1,vis);
        }
        if(j-1>=0 && b[i][j-1]==w[curr] && !flag && !vis[i][j-1]){
            func(b,i,j-1,w,curr+1,vis);
        }
        if(i+1<b.size() && b[i+1][j]==w[curr] && !flag && !vis[i+1][j]){
            func(b,i+1,j,w,curr+1,vis);
        }
        if(j+1<b[0].size() && b[i][j+1]==w[curr] && !flag && !vis[i][j+1]){
            func(b,i,j+1,w,curr+1,vis);
        }
        vis[i][j] = 0;
        return;
    }
};
