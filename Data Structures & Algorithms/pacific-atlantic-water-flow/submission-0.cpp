class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>>ans;
        if(h.size()<1) return ans;
        vector<vector<int>>pac(h.size(),vector<int>(h[0].size(),0));
        vector<vector<int>>atl(h.size(),vector<int>(h[0].size(),0));
        for(int i=0;i<h.size();i++){
            func(h,i,0,INT_MIN,pac);
            func(h,i,h[0].size()-1,INT_MIN,atl);
        }

        for(int j=0;j<h[0].size();j++){
            func(h,0,j,INT_MIN,pac);
            func(h,h.size()-1,j,INT_MIN,atl);
        }
        for(int i=0;i<h.size();i++){
            for(int j=0;j<h[0].size();j++){
                if(pac[i][j]==1 && atl[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    void func(vector<vector<int>>& h, int i, int j, int prev, vector<vector<int>>& ocean){
        if(i<0 || j<0 || i>=h.size() || j>=h[0].size()){
            return ;
        }
        if(h[i][j]<prev){
            return;
        }
        if (ocean[i][j] == 1) return;
        ocean[i][j] = 1;
        func(h,i-1,j,h[i][j],ocean);
        func(h,i+1,j,h[i][j],ocean);
        func(h,i,j-1,h[i][j],ocean);
        func(h,i,j+1,h[i][j],ocean);
    }
};
